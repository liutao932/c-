#include"data.h"
#pragma warning(disable:4996)
int main()
{
	int year, month, day;
	scanf("%4d%2d%2d", &year, &month, &day);
	//printf("%d-%d-%d", year, month, day);
	Data d1(year, month, day);
	while (!d1.Reverse())
	{
		++d1;
	}
	d1.print();
	++d1;
	while (!d1.Reverse())
	{
		++d1;
	}
	d1.print();
}