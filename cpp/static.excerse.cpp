//#include<iostream>
//using namespace std;
//
//class A
//{
//	friend int GetCount();
//	friend int GetCount(const A& a1);
//public:
//	A()
//	{
//		_Count++;
//	}
//	A(const A& d)
//	{
//		_Count++;
//	}
//	static int GetCount()  //静态成员函数没有this指针
//	{
//		return _Count;
//	}
//private:
//	//public:   
//	static int _Count;
//};
//
//int A::_Count = 0;  //静态成员在类外定义，定义是要加上作用域
//
//int GetCount()  //友元函数同样没有this指针
//{
//	return A::_Count;   //要声明属于那个对象
//}
//int GetCount(const A& a1)  //友元函数同样没有this指针
//{
//	return a1._Count;  //要声明属于那个对象
//}
//void f(A)
//{
//
//}
//int main()
//{
//	A a1;
//	A a2(a1);
//	f(a2);
//	//cout << A::_Count << endl;  //如果静态成员是公有那么可以在类外访问
//	cout << A::GetCount() << endl;   //静态成员函数可以用类引用
//	//cout << a1.GetCount() << endl;   尽量不要使用这种调用
//	cout << GetCount() << endl;
//	cout << GetCount(a1) << endl;
//}


//实现1+2+3+..+n

#include<iostream>
using namespace std;
class sum
{
public:
	sum()
	{
		_ret += _i;
		_i++;
	}
	static int  GetRet()
	{
		return _ret;
	}
private:
	static int _i;
	static int _ret;
};
int sum::_i = 1;
int sum::_ret = 0;

int main()
{

	int n;
	cin >> n;
	sum* p = new sum[n];
	cout << sum::GetRet() << endl;
}