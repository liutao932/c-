#pragma once
#include<iostream>
using namespace std;
#pragma warning(disable:4996)


class Data
{
public:
	Data(int year, int month, int day);

	int GetDay(int year, int month);

	bool operator>(const Data& d)const;
	bool operator==(const Data& d)const;
	bool operator!=(const Data& d)const;
	bool operator<(const Data& d)const;
	bool operator>=(const Data& d)const;
	bool operator<=(const Data& d)const;


	bool Reverse();
	Data& operator+=(int day);

	Data& operator++();

	void print()const;
private:
	int _year;
	int _month;
	int _day;
};
