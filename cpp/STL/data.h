#pragma once
#define _DATA_H
#ifdef _DATA_H
#include<iostream>
using namespace std;
class Data
{
	friend ostream& operator<<(ostream& out, const Data& d);
	friend istream& operator>>(istream& in, Data& d);
public:
	Data(int year = 1, int month = 1, int day = 1);
	void print()const;
	int GetDay(int year, int day);
	//运算符重载
	bool operator>(const Data& d)const;
	bool operator==(const Data& d)const;
	bool operator<=(const Data& d)const;
	bool operator>=(const Data& d)const;
	bool operator!=(const Data& d)const;
	bool operator <(const Data& d) const;

	Data& operator-=(const int day);
	Data operator-(const int day);
	Data& operator+=(const int day);
	Data operator+(const int day);

	Data& operator++();
	Data operator++(int); // 占位参数，后置++效率低，会生成2次拷贝构造

	Data& operator--();
	Data operator--(int);
	void PrintWeekDay() const; //获取星期几



	int operator-(const Data& d)const;

	~Data();

private:
	int _year;
	int _month;
	int _day;
};
#endif // DEBUG

