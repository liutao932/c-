#pragma once
#include"data.h"

int Data::GetDay(int year, int month)
{
	int ArrayMonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = ArrayMonthDay[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		day++;
	}
	return day;
}
//运算符重载
Data::Data(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (_year > 0 && (_month > 0 && _month < 13) && (_day > 0 && _day <= GetDay(_year, _month)))
	{
		cout << "data is legal" << endl;
	}
	else
	{
		cout << "data is illegality" << endl;
	}
}
void Data::print()const
{
	cout << _year << "/" << _month << "/" << _day << endl;
}
bool Data::operator>(const Data& d)const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Data::operator==(const Data& d)  const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// d1 < d2
bool Data::operator<(const Data& d)  const
{
	return !(*this >= d);
}

// d1 >= d2
bool Data::operator>=(const Data& d)  const
{
	return *this > d || *this == d;
}

bool Data::operator<=(const Data& d)  const
{
	return  !(*this > d);
}

bool Data::operator!=(const Data& d)  const
{
	return  !(*this == d);
}

//bool Data::operator==(const Data& d)const
//{
//	return _year == d._year && _month == d._month && _day == d._day;
//}
//bool Data:: operator <(const Data& d) const
//{
//	return !(*this >= d);
//}
//
//bool Data::operator<=(const Data& d)const
//{
//	return  !(*this > d);
//}
//bool Data::operator>=(const Data& d)const
//{
//	return (*this > d && *this == d);
//}
//bool Data::operator!=(const Data& d)const
//{
//	return !(*this == d);
//}

//算法
Data& Data::operator-=(const int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetDay(_year, _month);
	}
	return *this;
}
Data Data::operator-(const int day)
{
	Data ret(*this);
	ret -= day;
	return ret;
}
Data& Data::operator+=(const int day)
{
	_day += day;
	while (_day > GetDay(_year, _month))
	{
		_day -= GetDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
Data Data::operator+(const int day)
{
	Data ret(*this);
	ret += day;
	return ret;
}

int Data::operator-(const Data& d)const
{
	Data max = *this, min = d;
	int flag = 1, count = 0;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	while (min != max)
	{
		min += 1;
		count++;
	}
	return count * flag;
}
Data& Data::operator++()
{
	*this += 1;
	return *this;
}
Data Data ::operator++(int)
{
	Data ret(*this);
	*this += 1;
	return ret;
}
Data& Data::operator--()
{
	*this -= 1;
	return *this;
}
//void Data::PrintWeekDay() const
//{
////	const char* arr[] = { "星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期天" };
//	int count = *this - Data(1900, 1, 1);  //Data(1900,1,1)是匿名对象
//	cout << arr[count % 7] << endl;
//}
Data Data::operator--(int)
{
	Data ret(*this);
	*this -= 1;
	return ret;
}
ostream& operator<<(ostream& out, const Data& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}
istream& operator>>(istream& in, Data& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
Data::~Data()
{

}