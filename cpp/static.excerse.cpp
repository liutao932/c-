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
//	static int GetCount()  //��̬��Ա����û��thisָ��
//	{
//		return _Count;
//	}
//private:
//	//public:   
//	static int _Count;
//};
//
//int A::_Count = 0;  //��̬��Ա�����ⶨ�壬������Ҫ����������
//
//int GetCount()  //��Ԫ����ͬ��û��thisָ��
//{
//	return A::_Count;   //Ҫ���������Ǹ�����
//}
//int GetCount(const A& a1)  //��Ԫ����ͬ��û��thisָ��
//{
//	return a1._Count;  //Ҫ���������Ǹ�����
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
//	//cout << A::_Count << endl;  //�����̬��Ա�ǹ�����ô�������������
//	cout << A::GetCount() << endl;   //��̬��Ա����������������
//	//cout << a1.GetCount() << endl;   ������Ҫʹ�����ֵ���
//	cout << GetCount() << endl;
//	cout << GetCount(a1) << endl;
//}


//ʵ��1+2+3+..+n

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