#include <stdio.h>
#include <stdlib.h>
#include "List.h"
// CPP -> C plus plus

// ������ͻ����
// 1�������Լ�����ı������������ܸ�������������ͻ
// 2�����빫˾��Ŀ���Ժ�������Ŀͨ���Ƚϴ󡣶���Э��������ͬ��д�Ĵ��룬������ͻ��
// C����û�а취�ܺõĽ���������
// CPP���һ�����﷨�������ռ�

// ������һ����bit�������ռ� -- ��
//namespace bit
//{
//	// ���ǻ���ȫ�ֱ������ŵ���̬����
//	int rand = 0;
//	int a = 1;
//}
//
//int a = 0;
//
//int main()
//{
//	printf("hello world\n");
//	printf("%d\n", rand);
//	printf("%d\n", bit::rand);
//
//	int a = 1;
//	printf("%d\n", a);
//
//	printf("%d\n", ::a);
//
//	return 0;
//}

//namespace szy
//{
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
//namespace bit
//{
//	// 1�������ռ��п��Զ������/����/����
//	int rand = 10;
//
//	int Add(int left, int right)
//	{
//		return left + right + 10;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
////2. �����ռ����Ƕ��
//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//// 
//int main()
//{
//	bit::rand = 10;
//
//	struct bit::Node node;
//	bit::Add(1, 2);
//	szy::Add(1, 2);
//
//	N1::Add(1, 2);
//	N1::N2::Sub(3, 4);
//
//	struct szy::ListNode ln;
//	szy::ListInit();
//
//	return 0;
//}

// �����������ռ�չ�� -- չ����ȫ����
//using namespace szy;

// ����չ��ĳһ����������չ��
//using szy::ListNode;
//
//int main()
//{
//	struct ListNode ln;
//	szy::ListInit();
//
//	printf("%d\n", szy::rand);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;  // C++���ʵ�ֶ�����һ����std�������ռ���
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}

//#include <iostream>
////using namespace std;  // C++���ʵ�ֶ�����һ����std�������ռ���
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//
//	return 0;
//}

//#include <iostream>
////using namespace std;
//// ���õ�չ��
//using std::cout;
//using std::endl;
//
//int main()
//{
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//
//	return 0;
//}

#include <iostream>
using namespace std;

int main()
{
	cout << "hello world" << endl;
	cout << "hello world\n";
	printf("hello world\n");

	int i = 10;
	double d = 1.11;
	// �Զ�ʶ������
	cout << i << " " << d << endl;

	cin >> i >> d;

	cout << i << " " << d << endl;

	return 0;
}