#include"Data.h"


Data::Data(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!(_year > 0 && (_month > 0 && _month < 13) && (_day < GetDay(_year, _month))))
	{
		cout << "data is illegality" << endl;
	}
	else
	{
		cout << "data is legal" << endl;
	}
}
void Data::print()
{
	cout << _year << " " << _month << " " << _day << endl;
}
int Data::GetDay(const int& year, const int& month)
{
	static int ArrayMonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = ArrayMonthDay[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		++day;
	}
	return day;
}
bool Data::operator>(const Data& d)
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
bool Data :: operator==(const Data& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Data::operator!=(const Data& d)
{
	return !(*this == d);
}
bool Data :: operator<=(const Data& d)
{
	return !(*this > d);
}
bool Data::operator<(const Data& d)
{
	/*if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	//return !(*this > d && *this == d);
	return !(*this > d) && !(*this == d);
}
Data& Data::operator+=(const int day)
{
	_day += day;
	
	while (_day > GetDay(_year, _month))
	{
		
		_day -= GetDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 0;
		}
	}
	return *this;
}
//Data Data ::operator+(const int day)
//{
//	Data ret(*this);
//	//ret.operator+=(day);
//	ret._day += day;
//	return ret;
//}
Data& Data:: operator++()  //前置
{
	*this += 1;
	return *this;
}
//Data Data:: operator++(int) //后置--占位参数
//{
//	Data ret(*this);
//	*this += 1;
//	return ret;
//}
Data& Data::operator-=(const int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{	 
		--_month;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetDay(_year, _month);
		
	}
	return *this;
}
//Data Data :: operator-(const int day)
//{
//	Data ret(*this);
//	ret -= day;
//	return ret;
//}
int Data :: operator-(const Data& d)
{
	//Data MaxData = *this;
	//Data MinData = d;
	//if (_year < d._year)
	//{
	//	MaxData = d;
	//	MinData = *this;
	//}
	//else if (_year == d._year && _month < d._month)
	//{
	//	MaxData = d;
	//	MinData = *this;
	//}
	//else if (_year == d._year && _month < d._month && _day < d._day)
	//{
	//	MaxData = d;
	//	MinData = *this;
	//}
	//int sumday = 0;
	//if (MaxData._day < MinData._day)
	//{
	//	int retday = GetDay(MaxData._year, MaxData._month);
	//	retday += MaxData._day;
	//	MaxData._month--;
	//	sumday += (retday - MinData._day);
	//}
	//sumday += MaxData._day - MinData._day;
	//if (MaxData._month < MinData._month)
	//{
	//	MaxData._month += 12;
	//	MaxData._year--;
	//}
	//while (MinData._month < MaxData._month)
	//{
	//	sumday += GetDay(MaxData._year, MaxData._month % 12);
	//}
	///*while (MaxData._month < MinData._month)
	//{
	//	sumday += GetDay(MaxData._year, MaxData._month);
	//	MaxData._month++;
	//}*/
	//while (MinData._year < MaxData._year)
	//{
	//	static int retmonth2 = 1;
	//	sumday += GetDay(MinData._year, retmonth2);
	//	retmonth2++;
	//}
	//return sumday;


	int falg = 1, count = 0;
	Data max = *this, min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		falg = -1;
	}
	while (min != max)
	{
		count++;
		min += 1;
	}
	return count * falg;
}
//
Data::~Data()
{

}