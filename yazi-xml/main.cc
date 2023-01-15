#include "./xml/Xml.h"
using namespace yazi::xml;

#include <vector>
int main()
{
    // Xml s1("student1");
    // s1.attr("id", 100);
    // s1.attr("name", "张三");
    // s1.attr("class", "塔利班");
    // s1.text("我是一个恐怖分子");
    


    // Xml s2("student2");
    // s2.attr("id", true);
    // s2.attr("name", "李四");
    // s2.attr("class", "塔利班");
    // s2.text("我是一个恐怖分子");

    // int falg = s1.attr("id");
    // std::cout << falg << std::endl;
    // Xml root;
    // root.name("root");
    // root[0] = s1;
    // root[1] = s2;
    
    // std::cout << root.str() << std::endl;
    // root.clear();
    // return 0;
    Xml ip1("addr",{{"ip","192.168.0.2"},{"mac","AB-BI-B7-0C"}},"hello world");

    Xml root;
    root.name("CATALOG");
    root.load("./test_xml");
    // for(auto it = root.begin(); it != root.end(); ++it)
    // {
    //     std::cout << it->str() << std::endl;
    // }
    root["PLANT"].append(ip1);
    root["PLANT"].remove("addr");
    root.remove("PLANT");
    //std::cout <<  root.str() << std::endl;
    std::cout << root.str() << std::endl;
    root.clear();
    // Xml root;
    // root.name("root");
    // Xml ip("addr");
    // ip.attr("ip","192.168.0.1");
    // ip.attr("mac","AB-BI-B7-0C");
    // Xml ip1("addr",{{"ip","192.168.0.2"},{"mac","AB-BI-B7-0C"}});
    // root.append(ip);
    // root.append(ip1);
    // std::cout << root.str() << std::endl;
    //root.clear();
    // Xml ip("addr");
    // ip.attr("ip","192.168.0.0.1");
    // ip.attr("mac","AB-BI-B7-0C");
    // root.append(ip);
    // std::cout << root.str() << std::endl;
    // ip1.attr("ip","192.168.0.0.1");
    // ip1.attr("mac","AB-BI-B7-0C");
    // Xml ip1("addr");
    // ip1.attr("ip","192.168.0.0.1");
    // ip1.attr("mac","AB-BI-B7-0C");
    // Xml ip1("addr");
    // ip1.attr("ip","192.168.0.0.1");
    // ip1.attr("mac","AB-BI-B7-0C");
    // Xml ip1("addr");
    // ip1.attr("ip","192.168.0.0.1");
    // ip1.attr("mac","AB-BI-B7-0C");
}