#include <unordered_map>
#include "tcp_server.hpp"
#include "./json/json.h"
#include "./json/parser.h"
std::unordered_map<std::string, std::string> g_dict;
// void Translate(const std::string &req, std::string *resp)
// {
//     auto it = g_dict.find(req);
//     if (it == g_dict.end())
//     {
//         *resp = "未找到";
//         return;
//     }
//     *resp = it->second;
//     return;
// }
void Translate(const std::string &req, std::string *resp)
{
    // auto it = g_dict.find(req);
    // if (it == g_dict.end())
    // {
    //     *resp = "未找到";
    //     return;
    // }
    // *resp = it->second;
    // return;

    Json vaule;
    vaule.parse(req);
    if(vaule["bool"])
    {
        Json obj;
        //收到Json串这里可以有服务器自己处理业务
        //obj["服务器"] = "收到了";
        Json arr;
        arr[0] = "服务器收到客户端的数据了";
        arr[1] = "服务器发往客户端的协议为:932";
        arr[2] = 932;
        obj["服务器"] = arr;
        *resp = obj.str();
        obj.clear();
    }
    vaule.clear();
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage ./dict_server [ip] [port]\n");
        return 1;
    }
    // 1. 初始化词典
    g_dict.insert(std::make_pair("hello", "你好"));
    g_dict.insert(std::make_pair("world", "世界"));
    g_dict.insert(std::make_pair("bit", "贼NB"));
    // 2. 启动服务器
    TcpThreadServer server(argv[1], atoi(argv[2]));
    server.Start(Translate);
    return 0;
}