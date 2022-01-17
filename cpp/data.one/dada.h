#define _DATA_H_
#ifdef _DATA_H_ 
#include<iostream>
using namespace std;
class Data
{
public:
	Data(int year = 2022, int month = 10, int day = 1);
	//Data(const Data& d);  //拷贝构造
	int GetDay(const int &year,const  int &month);
	void print() const ;
	bool operator>(const Data& d)  const;
	bool operator<(const Data& d)  const;
	bool operator==(const Data& d) const ;
	bool operator<=(const Data& d) const;
	bool operator!=(const Data& d) const;
	Data& operator+=(const int day);
	Data operator+(const int day);
	Data& operator-=(const int day);
	Data operator-(const int day) const;
	int operator-(const Data& d) const;
	Data& operator++();
	//Data operator++(int); //后置--占位参数
	~Data();
private:
	int _year;
	int _month;
	int _day;
};
#endif // 

