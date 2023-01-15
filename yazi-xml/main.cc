#include "./xml/Xml.h"
using namespace yazi::xml;


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


    Xml root;
    root.load("./test_xml");
    std::cout << root.str() << std::endl;
    root.clear();
}