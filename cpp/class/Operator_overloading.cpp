#include<iostream>
using namespace std;



class Data
{
public:
	Data(int year = 2022, int month = 1, int day = 16)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//Data(const Data& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
	bool operator>(const Data& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_month == d._month && _day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	void print()
	{
		cout << _year << "_" << _month << "_" << _day<<endl;
	}
	~Data()
	{

	}
private:
	int _year;
	int _month;
	int _day;
};
//bool operator>(const Data& d1, const Data& d2)  //一般我们把运算符重载写进类中
//{
//	if (d1._year > d2._year)
//	{
//		return true;
//	}
//	else if(d1._year == d2._year && d1._month > d2._month)
//	{
//		return true;
//	}
//	else if (d1._month == d2._month && d1._day > d2._day)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
int main()
{
	//Data d1;
	//Data d2(2021,10,10);
	//Data d2(d1);    //调用的拷贝构造，默认调用的是浅拷贝，也就是memcpy，涉及深拷贝问题程序会崩溃
	//Data d2 = d1;   //这也是拷贝构造
	//d1.print();
	//d2.print();
	Data d1(2002,12,26);
	Data d2(2002,12,4);
	d1 += 100;
	//cout << operator>(d1, d2)<<endl;
	//cout << Data::operator>(&d1,&d2) << endl;
	cout << (d1 > d2) << endl;
}
