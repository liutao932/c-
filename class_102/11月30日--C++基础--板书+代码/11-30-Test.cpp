#include<iostream>
using namespace std;

// ���õļ�ֵ
// 1�������� --  a�����Ч�� b���βε��޸ģ�����Ӱ��ʵ�Σ�����Ͳ�����
//#define N  100
//const int N = 10;
//struct Stack
//{
//	//int* a;
//	//int top;
//	//int capacity;
//	int a[N];
//	int top;
//};
//
//void Func1(struct Stack st)
//{}
//
//void Func2(struct Stack* pst)
//{}
//
//void Func3(struct Stack& rst)
//{}
//
//void StackInit(struct Stack* pst)
//{}
//
//void StackInit(struct Stack& rst)
//{}
////
////int main()
////{
////	int a = 10;
////	int& b = a;
////	int& c = b;
////
////	struct Stack st1;
////	Func1(st1);
////	Func2(&st1);
////	Func3(st1);
////	StackInit(&st1);
////	StackInit(st1);
////
////	return 0;
////}
//
//// 2.����������ֵ
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//// int At(int i)
//int& At(int i)
//{
//	static int a[N];
//	return a[i];
//}
//
////int main()
////{
////	int ret = Add(1, 2);
////
////	for (size_t i = 0; i < N; ++i)
////	{
////		At(i) = 10+i;
////	}
////
////	for (size_t i = 0; i < N; ++i)
////	{
////		cout << At(i) << " ";
////	}
////	cout << endl;
////
////	return 0;
////}
//
//// ʹ�����ô��Σ���������в��ı������ֵ������ʹ��const &
//void StackPrint(const struct Stack& st)
//{}
//
////int main()
////{
////	// Ȩ�޷Ŵ� -- ����
////	const int a = 10;
////	//int& b = a;
////
////	// Ȩ�޲��� -- ����
////	const int c = 20;
////	const int& d = c;
////
////	// Ȩ����С -- ����
////	int e = 30;
////	const int& f = e;
////
////	double dd = 11.11;
////	int i1 = dd;
////	//int& i2 = d;
////	const int& i3 = dd;
////
////	int x1 = 1, x2 = 2;
////	const int& ret = x1 + x2;
////	printf("%p\n", &ret);
////
////	return 0;
////}
//
//void f1(int* p)
//{
//	*p = 10;
//}
//
//void f2(int& r)
//{
//	r = 10;
//}

//int main()
//{
//	//int x = 0;
//	//int& a = x;
//	//int* p;
//
//	f1(NULL);
//	f1(0);
//	//f2(NULL);
//	//f2(0);
//	int a = 0;
//	f1(&a);
//	f2(a);
//
//	return 0;
//}

//int main()
//{
//
//	return 0;
//}

//// C++��Ŀ
//// ����C++��������extern "C"{}����ĺ�����C����������ģ����ӵ�ʱ����C�ĺ���������ȥ�ң��Ϳ���������
//extern "C"
//{
//	#include "../../DS/DS/Stack.h"
//}
//
//bool isValid(char * s){
//	ST st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '('
//			|| *s == '{'
//			|| *s == '[')
//		{
//			StackPush(&st, *s); 
//			++s;
//		}
//		else
//		{
//			// �����������ˣ�����ջ����û�����ݣ�˵��
//			// ǰ��û�������ţ���ƥ�䣬����false
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//
//			STDataType top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == '}' && top != '{')
//				|| (*s == ']' && top != '[')
//				|| (*s == ')' && top != '('))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				++s;
//			}
//		}
//	}
//
//	// ���ջ���ǿգ�˵��ջ�л���������δ��
//	// û��ƥ�䣬������false
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
//
//int main()
//{
//	//cout << isValid("{[]}") << endl;
//	//cout << isValid("([)]") << endl;
//	printf("%d\n"isValid("{[]}"));
//	printf("%d\n"isValid("([)]"));
//
//	return 0;
//}


//// C ��Ŀ
//#include "../../DS/DS/Stack.h"
//
//bool isValid(char * s){
//	ST st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '('
//			|| *s == '{'
//			|| *s == '[')
//		{
//			StackPush(&st, *s);
//			++s;
//		}
//		else
//		{
//			// �����������ˣ�����ջ����û�����ݣ�˵��
//			// ǰ��û�������ţ���ƥ�䣬����false
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//
//			STDataType top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == '}' && top != '{')
//				|| (*s == ']' && top != '[')
//				|| (*s == ')' && top != '('))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				++s;
//			}
//		}
//	}
//
//	// ���ջ���ǿգ�˵��ջ�л���������δ��
//	// û��ƥ�䣬������false
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
//
//int main()
//{
//	//cout << isValid("{[]}") << endl;
//	//cout << isValid("([)]") << endl;
//	printf("%d\n", isValid("{[]}"));
//	printf("%d\n", isValid("([)]"));
//
//	return 0;
//}

// ���ú�������Ҫ����ջ֡��ջ֡��Ҫ����һЩ�Ĵ�������������Ҫ�ָ�...
// ���Կ�����Щ���������ĵġ�
// ����Ƶ�����õ�С�������ܷ��Ż�һ�£�
// C -- ��

//int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//
//	return 0;
//}

//  дһ����������ӵĺ� -- ���ɣ���ס��ԭ�����滻�����滻һ�¿����Բ���
//#define ADD(int x, int y) { return x + y;}
//#define ADD(int x, int y) return x + y;
//#define ADD(int x, int y) x + y;
//#define ADD(x, y) x + y;
//#define ADD(x, y) x + y
//#define ADD(x, y) (x + y)
#define ADD(x, y) ((x) + (y))

//int main()
//{
//	//cout << ADD(1, 2) << endl; // cout << 1 + 2; << endl; 
//	cout << ADD(3, 4) << endl;  // cout << 3 + 4 << endl;
//	cout << 10 * ADD(3, 4) << endl; // cout << 10*3+4 << endl;
//
//	int a = 0, b = 1;
//	cout << ADD(a | b, a&b) << endl; //cout << (a|b + a&b) << endl;
//
//	return 0;
//}

// ����inline, ���ǾͲ���Ҫ��C�ĺ꣬��Ϊ��ܸ��ӣ������׳���
inline int Add(int x, int y)
{
	int ret = x + y;
	return ret;
}

inline void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int ret = Add(1, 2);
	cout << ret << endl;

	int x = 0, y = 1;
	Swap(x, y);

	return 0;
}