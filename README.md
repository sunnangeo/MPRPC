protobuf:
1. 先写好.proto配置文件，然后command protoc --cpp_out = ./
2. 再编译 g++ -std=c++11 *.cc -o a `pkg-config --cflags --libs protobuf`

package->namespace
message->class
service->服务对象

在rpc提供服务这一方，如何把本地的服务提供成rpc服务？
1. 首先使用protoc把protobuf中的信息生成.pb.h和.pb.cc文件，这两个文件中把本地类的服务类生成了一个serviceRpc类继承了Service类，把本地类中的方法生成了一个虚函数等待用户重写，重写的过程首先要根据request获取参数的值，其次执行本地的服务，再把返回值打包填入到response，最后执行done->run()把response通过pb和muduo传到远端。框架把run方法重写了其实就是muduo应用把网络模块写好了。

rpcprovider：
服务端的提供方会通过rpcprovider，通过抽象的service把本地的服务对象以及所对应的服务方法记录在map中，然后执行run方法后会开启一个多线程的epoll，已建立连接的读写回调，如果远端有一个rpc请求，OnMessage方法就会响应，按照一定规则的数据格式解析出服务对象、方法、参数，然后通过抽象Message动态生成request，然后再生成一个回调，在框架上根据远端roc请求，调用当前rpc节点发布的方法
