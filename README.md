# MYRPC

## 一、分布式与RPC

### 单机→ 集群→ 分布式→ 微服务

单机：当服务的流量很小时，可以将所有的功能都部署在一台服务器上

​	1、随着流量的增长，受限于硬件资源，单机服务器不能承受用户的大量并发请求

​	2、任意模块的修改，都会导致整个项目代码重新编译、部署

​	3、系统中，有CPU密集型、IO密集型的模块，各个模块对于硬件的资源需求是不同的

集群：可以通过横向扩展服务器的数量，把同样的项目部署在多台服务器上提高用户的并发量

​	1、项目代码还是需要重新编译，而且要进行多次部署

分布式：把不同的业务模块部署在不同的服务器上，通过网络连接的多个组件，通过交换信息协作而形成的系统

1、大系统的软件模块该怎么划分

2、各个模块之间该怎么互相访问

### RPC

第二点可以使用RPC解决：可以通过网络从远程服务器上请求服务（调用远端服务器上的函数并获取返回结果）。简单来说，客户端程序可以像调用本地函数一样直接调用运行在服务端的函数。互联网上的机器大都通过[TCP/IP协议](http://en.wikipedia.org/wiki/Internet_protocol_suite)相互访问，但TCP/IP只是往远端发送了一段二进制数据，为了建立服务还有很多问题需要抽象，它把网络交互类比为“client访问server上的函数”：client向server发送request后开始等待，直到server收到、处理、回复client后，client又再度恢复并根据response做出反应。

## 二、RPC框架使用

### server端：

1、填写proto文件，其中package代表命名空间、message代表类，service代表服务对象，使用 option cc_generic_services = true;告诉protoc要生成C++ Service基类，服务提供方要实现protobuf生成的接口。

2、继承后重写基类的虚函数，重写的内容大致为从request中得到参数，处理本地业务，把返回值打包到response中，执行回调函数done把response序列化并发送至远端(BRPC中的回调建议使用**ClosureGuard**确保done->Run()被调用，不管在中间还是末尾脱离服务回调，都会使done_guard析构，其中会调用done->Run()。这个机制称为[RAII](https://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization)。没有这个的话你得在每次return前都加上done->Run()，**极易忘记**)。

3、要把服务加入Service，实参为子类的对象，形参为父类的指针，这样框架就可以接受不同的服务。

4、开启服务，一个服务只能监听一个端口。

### client端：

1、同样需要有proto文件，protoc后会生成一个_stub的类供用户端使用，这个类需要传入一个channel类参数

调用_stub的方法(对应的服务端发布的方法)，其实就是channel调用CallMethod，这之前需要把request装好，response和done不用装。一般来说，我们不直接调用channel.CallMethod，而是通过protobuf生成的桩XXX_Stub，过程更像是“调用函数”。

## 三、RPC框架结构

protobuf:
1. 先写好.proto配置文件，然后command protoc --cpp_out = ./ xxx.proto
2. 再编译 g++ -std=c++11 *.cc -o a `pkg-config --cflags --libs protobuf`

在rpc提供服务这一方，如何把本地的服务提供成rpc服务？
首先使用protoc把protobuf中的信息生成.pb.h和.pb.cc文件，文件中生成了UserServiceRpc这个类继承于Service类，用户把UserService继承UserServiceRpc，UserServiceRpc中的虚函数重写，重写的过程首先要根据框架已经打包好的request获取请求参数的值，其次执行本地的服务，再把返回值打包填入到response，最后执行done->run()把response通过pb和muduo传到远端。作为提供服务方，还要把rpc服务发布到rpc节点上，首先要初始化框架(框架值初始化一次就行了，要读取配置文件)，其次NotifyService(通过GetDescriptor得到服务对象的名字和服务方法的个数和名字，并把他们记录在一个map中)，最后run以阻塞方式等待远端调用rpc服务方法(使用muduo完成rpc的网络收发模块)，当有远端的请求到来时，之前绑定的OnMessage方法就会被muduo调用(在框架内部，MprpcProvider和RpcConsumer协商好之间通信用的protobuf数据类型，数据头：服务名，方法名，参数长度。解析muduo搞定的字符流，以二进制方法读取4个字节的header_size，再读取header_size长度的数据头，再读取arg_size长度的参数，把数据头中的service名字和method名字在map中寻找一下，通过proto的message中的getprototype生成request和response，然后把请求参数的字符串反序列化，然后再绑定一个closure回调函数用于把response序列化和通过muduo发送到远端(回调是由业务调用的)，最后调用Service->CallMethod，其实就是相当于调用UserService->Login方法)

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
