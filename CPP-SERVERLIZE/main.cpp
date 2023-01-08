#include <iostream>
using namespace std;

#include "DataStream.h"
using namespace yazi::serialize;
// class A : public Serializable
// {
// public:
//     A(){}
//     A(const std::string name,int age,const std::string addr) :_name(name),_age(age),_addr(addr){}
//     ~A() {}
//     void show()
//     {
//         std::cout << _name << " "<<  _age <<" " << _addr << std::endl;
//     }
//     SERIALIZE(_name,_age,_addr);
//     // void serizlize(DataStream& stream) const
//     // {
//     //     char type = DataStream::CUSTOM;
//     //     stream.write(static_cast<char *>(&type), sizeof(char));
//     //     stream.write(_name);
//     //     stream.write(_age);
//     //     stream.write(_addr);
//     // }
//     // bool unserialize(DataStream& stream)
//     // {
//     //     char type;
//     //     stream.read((char*)&type,sizeof(char));
//     //     if((DataStream::DataType)type != DataStream::DataType::CUSTOM)
//     //     {
//     //         return false;
//     //     }
//     //     stream.read(_name);
//     //     stream.read(_age);
//     //     stream.read(_addr);
//     //     return true;
//     // }
// private:
//     std::string _name;
//     int _age;
//     std::string _addr;
// };

int main()
{
    DataStream ds;
    int  a = 123;
    ds << a;

    int b;
    ds >> b;
    std::cout << b << std::endl;
    // DataStream ds;
    // A a("张三",18,"北京");
    // ds << a;

    // A b;
    // ds >> b;
    // b.show();
    // std::set<int> s{1, 2, 3, 4, 5};
    // ds << s;
    // std::set<int> s1;
    // ds >> s1;
    // for (const auto &e : s1)
    // {
    //     cout << e << endl;
    // }
    // std::map<std::string,int> mp = {{"123",1},{"aaa",2}};
    // ds.write(mp);
    // std::map<std::string,int> mp1;
    // ds.read(mp1);
    // for(const auto &e : mp1)
    // {
    //     std::cout << e.first << " " << e.second << endl;
    // }
    // std::vector<int> v{1,2,3,4,5,6};
    // ds.write(v);
    // //ds << v;
    // vector<int> v1;
    // //ds >> v1;
    // ds.read(v1);
    // for(auto e : v1)
    // {
    //     std::cout << e << std::endl;
    // }
    // DataStream ds;
    // ds << "hello c++" << 12.321321 << 123 << 1.23 << true << "hello world" << 'a' << 1.11101;
    // //网络通信
    // std::string a1;
    // float a2;
    // int a;
    // double b;
    // bool c;
    // std::string d;
    // char e;
    // double f;
    // std::string g;
    // double h;
    // ds  >> g >> h >> a >> b >> c >> d >> e >> f;
    // std::cout << g << " " << h << " " << a << " " << b << " " << c << " " << d << " " << e << " " << f << std::endl;
    // //  DataStream ds;
    //  ds << 123 << 1.23 << true << "hello world" << 'a'<< 1.11101;
    //  int a;
    //  double b;
    //  bool c;
    //  std::string d;
    //  char e;
    //  double f;
    //  ds >> a >> b >> c >> d >> e >> f;
    //  std::cout << a << " " << b << " " << c << " " << d <<" "<< e <<" "<< f <<std::endl;
    // int n = 123;
    // ds.write(n);
    // ds.show();
    // bool falg = false;
    // ds.write(falg);
    // ds.show();

    // char a = 'a';
    // ds.write(a);
    // int32_t n = 1234;
    // int64_t n = 123312312312312312;
    // float n = 13.14;
    // double n = 13.131;
    // bool falg = false;
    // falg >> ds;
    // char a = 'h';
    // a >> ds;
    // int n = 1234567665;
    // std::string n = "hello world";
    // ds << n;
    // float n = 12.123;
    //  double n1;
    // ds.read(n1);
    // std::cout << n1 << std::endl;
}