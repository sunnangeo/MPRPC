一、为什么要用这个框架：可以通过网络从远程服务器上请求服务（调用远端服务器上的函数并获取返回结果）。简单来说，客户端程序可以像调用本地函数一样直接调用运行在服务端的函数

protobuf:
1. 先写好.proto配置文件，然后command protoc --cpp_out = ./
2. 再编译 g++ -std=c++11 *.cc -o a `pkg-config --cflags --libs protobuf`

package->namespace
message->class
service->服务对象

必须加一个选项option生成

在rpc提供服务这一方，如何把本地的服务提供成rpc服务？
首先使用protoc把protobuf中的信息生成.pb.h和.pb.cc文件，文件中生成了UserServiceRpc这个类继承于Service类，用户把UserService继承UserServiceRpc，UserServiceRpc中的虚函数重写，重写的过程首先要根据框架已经打包好的request获取请求参数的值，其次执行本地的服务，再把返回值打包填入到response，最后执行done->run()把response通过pb和muduo传到远端。作为提供服务方，还要把rpc服务发布到rpc节点上，首先要初始化框架(框架值初始化一次就行了，要读取配置文件)，其次NotifyService(通过GetDescriptor得到服务对象的名字和服务方法的个数和名字，并把他们记录在一个map中)，最后run以阻塞方式等待远端调用rpc服务方法(使用muduo完成rpc的网络收发模块)，当有远端的请求到来时，之前绑定的OnMessage方法就会被muduo调用(在框架内部，MprpcProvider和RpcConsumer协商好之间通信用的protobuf数据类型，数据头：服务名，方法名，参数长度。解析muduo搞定的字符流，以二进制方法读取4个字节的header_size，再读取header_size长度的数据头，再读取arg_size长度的参数，把数据头中的service名字和method名字在map中寻找一下，通过proto的message中的getprototype生成request和response，然后把请求参数的字符串反序列化，然后再绑定一个closure回调函数用于把response序列化和通过muduo发送到远端(回调是由业务调用的)，最后调用Servive->CallMethod，其实就是相当于调用UserService->Login方法)

rpcprovider：
1. 使用muduo网络库实现的网络收发模块
2. 使用protobuf实现的onMessage回调中的数据反序列化模块
3. 通过NotifyService记录本地的rpc服务以及方法

在rpc调用这一方
首先有一个UserServiceRpc_Stub类用来调用rpc服务方法，必须要有一个MpRpcChannel继承于RpcChannel，父类的指针指向子类的对象，用Stub调用所有的方法都会调用RpcChannel的callmethod，MprpcChannel继承于RpcChannel，重写一下callmethod，集中来做所有rpc方法调用的参数序列化(在框架内部，MprpcProvider和RpcConsumer协商好之间通信用的protobuf数据类型，数据头：服务名，方法名，参数长度。组装要传过去的request的一些对象的值为字符流)和网络发送(不需要高并发，所以只需要TCP编程即可)

zookeeper:在分布式环境下，当某一个模块在多个服务器部署时，客户端需要知道有那些服务器提供服务，如果通过一个配置文件获取，当新增服务器或有服务器宕机，就会有问题，所以用zookeeper。首先这些服务会在注册中心进行注册，当客户端来查询的时候，只需要给出名称，注册中心就会给出一个URL。所有的客户端在访问服务前，都需要向这个注册中心进行询问，以获得最新的地址。注册中心可以是树形结构，每个服务下面有若干节点，每个节点表示服务的实例。注册中心和各个服务实例直接建立Session，要求实例们定期发送心跳，一旦特定时间收不到心跳，则认为实例挂了，删除该实例。

临时性节点&永久性节点

zk的数据是怎么组织的：znode：/服务名/服务方法 ls get
zk的watcher机制

在rpc提供方开一个zkClient把所有服务都注册在zk上，rpc调用方在拿到服务名字和方法后，开一个zkClient找到url
