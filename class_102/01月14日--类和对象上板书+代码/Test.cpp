#include<iostream>
#include<map>
#include <string>
#include<assert.h>
//using namespace std;
// 1���ճ���ϰ����̫�ں�������Ⱦ��using namespace std;ȫ��չ��
// 2����Ŀ�У���Ҫȫ��չ���� ָ�����ʻ���չ������
using std::cout;
using std::endl;

//int main()
//{
//	// IO��
//	int i = 0;
//	double d;
//	std::cin >> i;  // ����ȡ
//	std::cin >> d;
//	cout << i << d << endl; // ������
//	cout << "hello world" << endl;
//
//	return 0;
//}

//
//int main()
//{
//	int a = 0;
//
//	// һ����������
//	int& b = a;   // ����
//	int* p = &b;  // ȡ��ַ
//
//	// ����ȡ�����Ĺ����У�Ȩ�޿�����С���߲��䣬���ǲ��ܷŴ�
//	const int c = 10;
//	// int& d = c;    // �Ŵ�
//	const int& d = c; // �Ŵ�
//	const int& f = a; // ��С
//
//	double dd = 1.1;
//	int ii = dd; // ����ת�� -- �м������ʱ����
//	const int& rii = dd;
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int& b = a;
//
//	int* p = &a;
//
//	b = 2;
//	*p = 3;
//
//	char ch = 'a';
//	char& rch = ch;
//	cout << sizeof(rch) << endl;
//
//	return 0;
//}

//int main()
//{
//	const int a = 0;
//	int b = 0;
//	// �Զ��Ƶ�c������
//	auto c = a;
//	auto d = 'A';
//	auto e = 10.11;
//
//	// typeid��ӡ����������
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//
//	// ʵ���У����ǲ�������������ȥ��auto
//	// ʵ����ʹ�ó���
//	std::map<std::string, std::string> dict = {{ "sort", "����" }, { "insert", "����" }
//};
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	// �����ұߵ�ֵȥ�Զ��Ƶ�it�����ͣ�д�����ͷ�����
//	auto it = dict.begin();
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;  // int*
//	auto* b = &x; // int*
//	auto& c = x;  // int
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	*a = 20;
//	*b = 30;
//	 c = 40;
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	const auto y = x;
//	//y = x;
//	//cout << typeid(y).name() << endl;
//
//	return 0;
//}

// �˴��������ʧ�ܣ�auto������Ϊ�β����ͣ���Ϊ�������޷���a��ʵ�����ͽ����Ƶ�
//void TestAuto(auto a)
//{}

//int main()
//{
//	int i = 0;
//	auto j = i;
//	//auto b[3] = { 4, 5, 6 };
//
//	return 0;
//}

//void TestFor(int a[])
//{
//	// ��Χ������������
//	for (auto& e : a)
//		cout << e << endl;
//}

//int main()
//{
//
//	// �﷨�� -- ��Χfor
//	int array[] = { 1, 2, 3, 4, 5 };
//
//	TestFor(array);
//
//	// C/C++ ��������
//	/*for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	{
//		cout << array[i] << endl;
//	}*/
//
//	// C++11 ��Χfor
//	// �Զ�����ȡ����array�е�ÿ��Ԫ�ظ�ֵ��e
//	/*for (auto e : array)
//	{
//	cout << e << endl;
//	}
//
//	for (int x : array)
//	{
//	cout << x << endl;
//	}*/
//
//	// ��Χfor ��������ÿ��ֵ+1
//	for (auto& e : array)
//	{
//		e++;
//	}
//
//	for (auto e : array)
//	{
//		cout << e << endl;
//	}
//
//	return 0;
//}
//

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()
//{
//	// C++98/03
//	int* p1 = NULL;
//	int* p2 = 0;
//
//	// C++11 ��ʼ����ָ���Ƽ�����nullptr
//	int* p3 = nullptr;
//
//	f(NULL);
//	f(0);
//	f(nullptr);
//
//	return 0;
//}

//struct/class
// C++ ����C����ṹ����÷�
// ͬʱstruct��C++��Ҳ����������
//struct Student
//{
//	char name[10];
//	int  age;
//	int  id;
//};
//
//struct ListNode
//{
//
//};
//
//int main()
//{
//	// ListNode* node;
//	// struct ListNode* node;
//
//	struct Student s1; // ����c
//	Student s2;        // �������࣬Student������Ҳ������
//
//	strcpy(s1.name, "����");
//	s1.id = 1;
//	s1.age = 18;
//
//	strcpy(s2.name, "����");
//	s2.id = 2;
//	s2.age = 19;
//
//
//	return 0;
//}


// struct/class
// C++ ����C����ṹ����÷�
// ͬʱstruct��C++��Ҳ����������
// C++����ṹ�岻ͬ�ǳ��˿��Զ�����������ǿ��Զ�����/����
//struct Student
//{
//	// ��Ա����
//	char _name[10];
//	int  _age;
//	int  _id;
//
//	// ��Ա����/��Ա����
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//};
//
//int main()
//{
//	// ListNode* node;
//	// struct ListNode* node;
//
//	struct Student s1; // ����c
//	Student s2;        // �������࣬Student������Ҳ������
//
//	s1.Init("����", 18, 1);
//	s2.Init("����", 19, 2);
//
//	s1.Print();
//	s2.Print();
//
//	return 0;
//}

// ����c struct���÷�����
//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void StackInit(ST* ps);
//void StackDestroy(ST* ps);
//void StackPush(ST* ps, STDataType x);
//void StackPop(ST* ps);
//STDataType StackTop(ST* ps);
//int StackSize(ST* ps);
//bool StackEmpty(ST* ps);
//
//// C�Ŀ�
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0; // ps->top = -1;
//	ps->capacity = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType)*newCapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	ps->top--;
//}
//
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	return ps->a[ps->top - 1];
//}
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//
//	return ps->top;
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//
//	/*if (ps->top == 0)
//	{
//	return true;
//	}
//	else
//	{
//	return false;
//	}*/
//	return ps->top == 0;
//}
//
//int main()
//{
//	//ST st;
//	//struct Stack st;
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//
//	return 0;
//}

// ��������������ԣ���װ���̳С���̬
// ��װ: 1�����ݺͷ������ŵ���һ���������� 2�������޶���
// һ���ڶ������ʱ�򣬽�����ȷ��������޶�������Ҫ��class/structĬ���޶�
//class Student
//{
//private:
//	// ��Ա����
//	char _name[10];
//	int  _age;
//	int  _id;
//
//public:
//	// ��Ա����/��Ա����
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//};
//
//class Stack
//{
//public:
//	void Init()
//	{
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		
//	}
//
//	int Top()
//	{
//		assert(_top > 0);
//		return _a[_top - 1];
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	// ListNode* node;
//	// struct ListNode* node;
//
//	struct Student s1; // ����c
//	Student s2;        // �������࣬Student������Ҳ������
//
//	s1.Init("����", 18, 1);
//	s2.Init("����", 19, 2);
//
//	s1.Print();
//	s2.Print();
//
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	int top = st.Top();
//
//	return 0;
//}

#include "Stack.h"

// ���н��г�Ա����
class A2 {
public:
	void f2() {}
};

// ����ʲô��û��---����
class A3
{};

// ���ۣ����������������С��ֻ����Ա�����������ڴ���룬C++�ڴ��������c�ṹ��һ��
int main()
{
	// �����д��˳�Ա�������Ƿ���˳�Ա�����أ�û���Ա����
	//Stack s;
	////s._a
	//s.Init();

	//cout << sizeof(Stack) << endl;
	//cout << sizeof(s) << endl;

	Stack s1;
	Stack s2;
	// ÿ�������ж��ж����ĳ�Ա����
	s1._top = 0;
	s2._top = -1;

	// ��ͬ������ó�Ա����������ͬһ��
	s1.Init();
	s2.Init();

	// ������1byte����1byte���洢��Ч���ݣ�ֻ��Ϊ��ռλ����ʾ�������
	A2 aa;
	A2 bb;
	cout << &aa << endl;
	cout << &bb << endl;

	return 0;
}