#include"stack.h"

stack::stack(int capatity)
	: _a(new int [capatity] {0})
	, _size(0)
	, _capatity(capatity)
{

}
void stack::push(int x)
{
	if (_size == _capatity)
	{
		int* tmp = new int[2 * _capatity];
		memcpy(tmp, _a, sizeof(int) * _size);
		delete[]_a;
		_a = tmp;
		_capatity = 2 * _capatity;
	}
	_a[_size] = x;
	++_size;
}
void stack::Print()
{
	for (int i = 0; i < _size; ++i)
	{
		cout << _a[i] << " ";
	}
	cout << endl;
}
void stack::pop()
{
	_size--;
}
int  stack::top()
{
	return _a[_size -1];
}
bool stack::empty()
{
	return _size == 0;
}
stack::~stack()
{
	delete[]_a;
	_size = _capatity = 0;
}