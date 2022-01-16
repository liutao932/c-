#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};
class Stack
{
public:
	Stack(int capatity = 4)
	{
		cout << "Stack()" << endl;
		_capatity = capatity;
		_a = (int*)malloc(sizeof(int) * capatity);
		_size = 0;
	}
	void push()
	{

	}
	void top()
	{

	}
	~Stack()
	{
		cout << "~stack()" << endl;
		free(_a);
		_a = nullptr;
		_size = _capatity = 0;
	}
private:
	int* _a;
	size_t _size;
	size_t _capatity;
	A a;
};


int main()
{
	Stack s(20);
}
