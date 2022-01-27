#include"data.h"
Data::Data(int year, int month, int day) :_year(year), _month(month), _day(day) {};

int Data::GetDay(int year, int month)
{
	static int ArrayMonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = ArrayMonthDay[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day++;
	}
	return day;
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
bool Data::operator==(const Data& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Data::operator!=(const Data& d)const
{
	return !(*this == d);
}
bool Data::operator<(const Data& d)const
{
	return !(*this >= d);
}
bool Data::operator>=(const Data& d)const
{
	return (*this > d || *this == d);
}
bool Data::operator<=(const Data& d)const
{
	return !(*this > d);
}

Data& Data::operator+=(int day)
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
bool Data::Reverse()
{
	Data ret(*this);
	int Array[8] = { 0 };
	int pos = 7;
	if (ret._day < 10)
	{
		Array[pos--] = ret._day;
		Array[pos--];
	}
	else
	{
		while (ret._day)
		{
			Array[pos--] = ret._day % 10;
			ret._day /= 10;
		}
	}
	if (ret._month < 10)
	{
		Array[pos--] = ret._month;
		Array[pos--];
	}
	else
	{
		while (ret._month)
		{
			Array[pos--] = ret._month % 10;
			ret._month /= 10;
		}
	}
	while (ret._year)
	{
		Array[pos--] = ret._year % 10;
		ret._year /= 10;
	}
	int left = 0, rigth = 7;
	while (left < rigth)
	{
		if (Array[left] != Array[rigth])
		{
			return false;
		}
		left++;
		rigth--;
	}
	return true;
}
Data& Data::operator++()
{
	*this += 1;
	return *this;
}

void Data::print()const
{
	if (_month < 10)
	{
		if (_day < 10)
		{
			cout << _year << "-0" << _month << "-0" << _day << endl;
		}
		else
		{
			cout << _year << "-0" << _month << "-" << _day << endl;
		}
	}
	else
	{
		if (_day < 10)
		{
			cout << _year << "-" << _month << "-0" << _day << endl;
		}
		else
		{
			cout << _year << "-" << _month << "-" << _day << endl;
		}
	}
	
}