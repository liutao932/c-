//#include<iostream>
////#include<iostream.h> // vc6.0 -> �Ƚ��ϰ汾�Ŀ⣬û�������ռ��
//using namespace std;

#include "Stack.h"

struct Student
{
	char name[20];
	int age;
	// ...
};

//int main()
//{
//	// << ������
//	// �Ƽ��������ã��ĸ���������ĸ�
//	cout << "hello world" << endl;
//	const char* str = "hello bit";
//	cout << str << endl;
//	int i = 1;
//	double d = 1.11;
//	cout << i << d << endl;
//	printf("%d%.2lf\n", i, d);
//
//	struct Student s = { "����", 18 };
//	// cpp
//	cout <<"����:" <<s.name << endl;
//	cout << "����:" << s.age << endl << endl;
//
//	// c
//	printf("����:%s\n����:%d\n", s.name, s.age);
//
//	// >> ����ȡ�����
//	cin >> s.name >> s.age;
//	cout << "����:" << s.name << endl;
//	cout << "����:" << s.age << endl << endl;
//
//	scanf("%s%d", s.name, &s.age);
//	printf("����:%s\n����:%d\n", s.name, s.age);
//
//	return 0;
//}

// ȱʡ����
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//
//int main()
//{
//	Func(1);
//	Func();
//
//	return 0;
//}

// ȫȱʡ
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func();
//	Func(1);
//	Func(1,2);
//	Func(1, 2, 3);
//
//	return 0;
//}

// ��ȱʡ -- ȱʡ���ֲ��� -- �����������ȱʡ,��������ȱʡ
//void Func(int a, int b = 20, int c = 30)
////void Func(int a, int b, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func(1);
//	Func(1, 2);
//	Func(1, 2, 3);
//
//	return 0;
//}

//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//
//void StackInit(struct Stack* ps, int capacity = 4)
//{
//	ps->a = (int*)malloc(sizeof(int)*capacity);
//	// 
//	ps->top = 0;
//	ps->capacity = capacity;
//}
//
//void StackPush(struct Stack* ps, int x)
//{
//	// ...
//}
//
//int main()
//{
//	struct Stack st;
//	//StackInit(&st); // ��֪��ջ����������ݣ�����ȱʡֵ��ʼ��
//	StackInit(&st, 100); // ֪��ջ����100���ݣ���ʾ��ֵ���������Լ������ݴ��������Ч��
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////
// ��������
// 1���������Ͳ�ͬ
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//
//	return left + right;
//}
//
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//// 3������˳��ͬ
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//
//// ����ֵ��ͬ�����ܹ������� -- ���õ�ʱ��������
////int f(double d)
////{
////
////}
////
////void f(double d)
////{
////
////}
//
//int main()
//{
//	Add(1, 2);
//	Add(1.1, 2.2);
//
//	f();
//	f(1);
//
//	f(10, 'A');
//	f('A', 10);
//
//	f(1.1);
//
//	return 0;
//}

// 1��ȱʡֵ��ͬ�����ܹ�������
//void f(int a)
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 0)
//{
//	cout << "f(int a)" << endl;
//}

// 2���������أ�����ʹ��ʱ�������� �� f(); // ���ô�������
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 0)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	// f(); // ���ô�������
//	 f(1);
//
//	return 0;
//}


//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}

int main()
{/*
	f();
	f(1);*/

	return 0;
}