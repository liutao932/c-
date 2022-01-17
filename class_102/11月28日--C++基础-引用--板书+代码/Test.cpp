#include<iostream>
using namespace std;

#include "SList.h"

//int main()
//{
//	int a = 10;
//	// ���ö���
//	int& b = a;
//
//	// ȡ��ַ
//	int* p = &b;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//
//	a = 20;
//	b = 30;
//
//	return 0;
//}

//int main()
//{
//	// 1��������**����ʱ�����ʼ��**
//	//int a = 10;
//	//int& b;
//
//	// 2��һ�����������ж������
//	//int a = 10;
//	//int& b = a;
//	//int& c = a;
//	//int& d = b;
//	//double d = 1.1;
//
//	// 3������һ������һ��ʵ�壬�ٲ�����������ʵ��
//	int a = 10;
//	int& b = a;
//
//	int c = 20;
//	// 1����������b���c�ı����أ� ��
//	// 2�����ǰ�c��ֵ��b�� ��
//	b = c;
//
//	//int* p1 = &a;
//	//p1 = &c;
//
//	return 0;
//}

// 1������������
// _Z4swappipi
void swap(int* p1, int* p2) // ����ַ
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// _Z4swapriri
void swap(int& r1, int& r2) // ������
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

// _Z4swapii
//void swap(int r1, int r2)   // ��ֵ
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}

// �����������ɺ�������
// ����swap(x, y);����ʱ�������壬����֪�����ã���ֵ���Ǵ�����
// ������ǰ�������,���ǹ������أ����Ǵ�������
// void f();
// void f(int x = 0, int y = 0);

//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//	swap(x, y);
//
//	return 0;
//}

int* singleNumbers(int* nums, int numsSize, int& returnSize){
//int* singleNumbers(int* nums, int numsSize, int* returnSize){
	int* a = (int*)malloc(sizeof(int) * 2);

	//...

	//*returnSize = 2;
	returnSize = 2;
	return a;
}

int TestList()
{
	SLTNode* plist = NULL;
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);
	SListPushFront(plist, 5);
	SListPushFront(plist, 6);
	SListPushFront(plist, 7);

	SListPrint(plist);

	int a = 10;
	int& b = a;

	int* p1 = &a;
	int*& p2 = p1;

	return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
};

//struct TreeNode* CreateTree(char* str, int* pi)
struct TreeNode* CreateTree(char* str, int& i)
{
	if (str[i] == '#')
	{
		(i)++;
		return NULL;
	}

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = str[i++];
	root->left = CreateTree(str, i);
	root->right = CreateTree(str, i);

	return root;
}

void InOrder(struct TreeNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

//int main()
//{
//	char str[100];
//	while (scanf("%s", str) != EOF)
//	{
//		int j = 0;
//		struct TreeNode* root = CreateTree(str, j);
//		InOrder(root);
//	}
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////
// ��ֵ����ֵ
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}

// �����÷���
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl;
//	//Add(10, 20);
//	printf("11111111111111111111111111111111111111\n");
//	cout << ret << endl;
//
//	return 0;
//}

#include <time.h>
struct A{ int a[10000]; };

A a;
// ֵ���� -- ÿ�ο���40000byte
A TestFunc1() { return a; }

// ���÷��� -- û�п���
A& TestFunc2(){ return a; }

void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

void TestFunc1(A a){}

void TestFunc2(A& a){}

void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

//void f(int a);
//void f(int& r);
// �ܽ�һ�£����õ�������Ҫ�����ڴ��κʹ�����ֵ
// 1�����ô��κʹ�����ֵ����Щ�������棬����������ܡ��������+�������--�����ѧ��
// 2�����ô��κʹ�����ֵ������Ͳ���������ͷ���ֵ��ͨ�׵�˵����Щ�������棬�βεĸı���Ըı�ʵ�Ρ�
// ��Щ��������,���÷��أ����Ըı䷵�ض���--�˽�һ�£������ѧ
//
//int main()
//{
//	TestReturnByRefOrValue();
//	TestRefAndValue();
//
//	return 0;
//}

// ����x��һ�����������Ǻ���ѧϰ����Ķ���
// ��ô���������ô��Σ����ٿ��������f�����в��ı�x
// ���龡����cosnt���ô���
//void f(int& x)
void f(const int& x)
{
	cout << x << endl;
}

// ������
int main()
{
	// Ȩ�޷Ŵ�  ������
	//const int a = 10;
	//int& b = a;

	// Ȩ�޲��� ����
	const int a = 10;
	const int& b = a;

	// Ȩ�޵���С ����
	int c = 10;
	const int& d = c;

	f(a);
	f(c);
	f(10);

	return 0;
}