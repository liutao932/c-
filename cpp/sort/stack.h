#pragma once
#include<iostream>
using namespace std;
class stack
{
public:
	stack(int capatity = 4);
	void push(int x);
	void pop();
	int  top();
	bool empty();
	void Print();
	~stack();
private:
	int* _a;
	int _size;
	int _capatity;
};


