#include <iostream>
using namespace std;


#include "json/json.h"
using namespace yazi::json;
#include <fstream>
void Test1(void)
{
    const std::string& str = "[1, \"a\", 3, null, -1.2345, true, false, \"hello world\"]";
    Json v;
    v.parse(str);
    std::cout << v.str() << std::endl;
}
void Test2(void)
{
    const std::string& str = "{\"a\":true,\"b\":{\"a\":true,\"b\":[1, \"a\", 3, null, -1.2345, true, false, \"hello world\"],\"c\":123,\"4\":\"hello world\"},\"c\":123,\"4\":\"hello world\"}";
    Json v;
    v.parse(str);
    std::cout << v.str() << std::endl;
}
void Test3()
{
    ifstream in("./json_test");
    stringstream ss;
    ss << in.rdbuf();
    const std::string& str = ss.str();
    //std::cout << str << std::endl;
     Json v;
     v.parse(str);
     //std::cout << v.str() << std::endl;
    std::cout << v["data"]["search_data"][0]["elements"][0]["name"].str() << std::endl;
}
int main()
{
    Test3();
    //Test2();
    //Test1();

    // Json v1;
    // Json v2 = true;
    // Json v3 = 123;
    // Json v4 = 1.23;
    // Json v5 = "hello";
    // bool b = v2;
    // int i = v3;
    // double f = v4;
    // const std::string& s = v5;
    // cout << b  << " " << i <<" "  << f << " "  << s << endl;

    //  Json arr;
    //  arr[1] = true;
    //  arr[2] = 123;
    //  arr[3] = 1.23;
    //  arr[4] = "hello";
    //  /*std::cout << arr.has(0) << std::endl;
    //  std::cout << arr.has(4) << std::endl;*/
     
    //  Json obj;
    //  obj["bool"] = true;
    //  obj["int"] = 123;
    //  obj["double"] = 1.23;
    //  obj["arr"] = arr;
    //  std::cout << obj.str() << std::endl;
    //  obj.clear();
}