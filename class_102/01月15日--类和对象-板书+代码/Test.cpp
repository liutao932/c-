#include <iostream>
using namespace std;

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		Date::year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 1, 15);
//
//	return 0;
//}

//class Date
//{
//public:
//	//void Init(Date* const this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	//void Print(Date* const this)
//	void Print()
//	{
//		//this = nullptr;
//		cout << _year << "-" << _month << "-" << _day << endl;
//
//		// һ����������Ƕ�����������������ʾд
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 1, 15);// d1.Init(&d1, 2022, 1, 15);
//	d1.Print();          // d1.Print(&d1);
//
//	Date d2;
//	d2.Init(2022, 1, 16); // d2.Init(&d2, 2022, 1, 16);
//	d2.Print();           // d2.Print(&d2);
//
//
//	/*const int* p1 = nullptr;
//	int* p2 = nullptr;
//	p1 = p2;
//	p2 = p1;*/
//
//	return 0;
//}

//class A
//{
//public:
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Show();
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//}

///////////////////////////////////////////////////////////////////////
//int main()
//{
//	Stack st;
//	// ���ǵ��ó�ʼ��
//
//	StackPush(&st, 1);
//	StackPush(&st, 1);
//	StackPush(&st, 1);
//
//	// ���ǵ������ٺ���
//
//	return 0;
//}

//class Date
//{
//public:
//	/*Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	
//	// �﷨���޲κ�ȫȱʡ�Ŀ���ͬʱ����
//	// ������������޲ε��ã��ͻ���ڶ�����
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	// �Ƽ�ʵ��ȫȱʡ���߰�ȱʡ����Ϊ�ȽϺ���
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//Date d1;
//	Date d2(2020);
//	Date d3(2020, 2);
//	Date d4(2022, 1, 15);
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << " A()" << endl;
//		_a = 0;
//	}
//
//	/*A(int a = 0)
//	{
//	cout << " A()" << endl;
//	_a = a;
//	}*/
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//private:
//	// C++��������ͷ�Ϊ���ࣺ��������(��������)���Զ�������
//	// �������ͣ�int/char/double/ָ��/������������ �ȵ�
//	// �Զ������ͣ�struct/class���������
//
//	// ���ǲ�д������Ĭ�����ɹ��캯���������������Ͳ�����ʼ������
//	// �����Զ����ͳ�Ա������ȥ��������Ĭ�Ϲ��캯����ʼ�������û��Ĭ�Ϲ��캯���ͻᱨ��
//	// �κ�һ�����Ĭ�Ϲ��캯������--���ò����Ϳ��Ե��á�
//	// �κ�һ�����Ĭ�Ϲ��캯����������ȫȱʡ���޲Ρ����ǲ�д������Ĭ�����ɵġ�
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa;
//};
//
//int main()
//{
//	Date d1;
//	d1.Date();
//
//	return 0;
//}



//class Date
//{
//public:
//	// �Ƽ�ʵ��ȫȱʡ���߰�ȱʡ����Ϊ�ȽϺ���
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		// Date��û����Դ��Ҫ��������Date��ʵ�������������ǿ��Ե�
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail\n" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{}
//
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2022, 1, 15);
//
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}


//class Date
//{
//public:
//	// �Ƽ�ʵ��ȫȱʡ���߰�ȱʡ����Ϊ�ȽϺ���
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		// Date��û����Դ��Ҫ��������Date��ʵ�������������ǿ��Ե�
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail\n" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{}
//
//	// ������ǲ�дĬ���������������͹��캯������
//	// �����������Ͳ�������
//	// �����Զ������ͻ�ȥ����������������
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//// ����ջʵ��һ������
//class MyQueue {
//public:
//	// Ĭ�����ɹ��캯����������������Զ������ͳ�Ա�������Ĺ��������
//	void push(int x) {
//
//	}
//private:
//	Stack pushST;
//	Stack popST;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2022, 1, 15);
//
//	Stack s1;
//	Stack s2(20);
//
//	MyQueue mq;
//
//	return 0;
//}

class A
{
public:
	A()
	{}

	A(const A&)
	{
		cout << "A(const A&)" << endl;
	}
};

class Date
{
public:
	// �Ƽ�ʵ��ȫȱʡ���߰�ȱʡ����Ϊ�ȽϺ���
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// Date d2(d1);
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	//d._year = _year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	~Date()
	{
		// Date��û����Դ��Ҫ��������Date��ʵ�������������ǿ��Ե�
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;

	A _aa;
};

class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int)*capacity);
		if (_a == nullptr)
		{
			cout << "malloc fail\n" << endl;
			exit(-1);
		}

		_top = 0;
		_capacity = capacity;
	}

	void Push(int x)
	{}

	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _a;
	size_t _top;
	size_t _capacity;
};

void f(Date& d)
{

}

int main()
{
	Date d1(2022, 1, 15);
	f(d1);

	// ��������
	Date d2(d1);

	Stack st1(10);

	// ��������
	Stack st2(st1);

	return 0;
}