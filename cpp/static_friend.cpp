#include<iostream>
using namespace std;

class A
{
	friend int GetCount1();
	friend int GetCount1(const A &a1);
public:
	A()
	{
		_Count++;
	}
	A(const A& d)
	{
		_Count++;
	}
	static int GetCount()  //��̬��Ա����û��thisָ��
	{
		return _Count;
	}
private:
//public:   //
	static int _Count;
};

int A::_Count = 0;  //��̬��Ա�����ⶨ�壬������Ҫ����������

int GetCount1()  //��Ԫ����ͬ��û��thisָ��
{
	return A::_Count;   //Ҫ���������Ǹ�����
}
int GetCount1(const A &a1)  //��Ԫ����ͬ��û��thisָ��
{
	return a1._Count;  //Ҫ���������Ǹ�����
}
void f(A)
{

}
int main()
{
	A a1;
	A a2(a1);
	f(a2);
	//cout << A::_Count << endl;  //�����̬��Ա�ǹ�����ô�������������
	cout << A::GetCount() << endl;   //��̬��Ա����������������
	//cout << a1.GetCount() << endl;   ������Ҫʹ�����ֵ���
	cout << GetCount1() << endl;
	cout << GetCount1(a1) << endl;
}