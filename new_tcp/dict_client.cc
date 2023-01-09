#include "tcp_client.hpp"
#include <iostream>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage ./dict_client [ip] [port]\n");
        return 1;
    }
    TcpClient client(argv[1], atoi(argv[2]));
    bool ret = client.Connect();
    if (!ret)
    {
        return 1;
    }
    // for (;;)
    // {
    //     std::cout << "请输入要查询的单词:" << std::endl;
    //     std::string word;
    //     std::cin >> word;
    //     if (!std::cin)
    //     {
    //         break;
    //     }
    //     client.Send(word);
    //     std::string result;
    //     client.Recv(&result);
    //     std::cout << result << std::endl;
    // }
    for (;;)  //客户端创建json串发往服务器
    {
        std::cout << "请输入你的协议:" << std::endl;
        // const std::string& str = "{\"a\":true,\"b\":{\"a\":true,\"b\":[1, \"a\", 3, null, -1.2345, true, false, \"hello world\"],\"c\":123,\"4\":\"hello world\"},\"c\":123,\"4\":\"hello world\"}";
        // Json v;
        // v.parse(str);
        // std::cout << v.str() << std::endl;
        // client.Send(v.str());
        Json arr;
        arr[1] = true;
        arr[2] = 123;
        arr[3] = 1.23;
        arr[4] = "hello";
        Json obj;
        obj["bool"] = true;
        obj["int"] = 123;
        obj["double"] = 1.23;
        obj["arr"] = arr;
        std::cout << obj.str() << std::endl;
        client.Send(obj);
        obj.clear();

        Json result;
        // client.Recv(result);
        // std::string result;
        client.Recv(&result);
        std::cout << result.str() << std::endl;
    }
    return 0;
}