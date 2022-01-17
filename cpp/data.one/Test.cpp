#include"Data.h"

void DataTest(void)
{
	Data d1(2021,12,20);
	d1.print();
	Data d2(2022,1,3);
	d2.print();
	////cout << (d1 > d2) << endl;
	//cout << (d1 < d2) << endl;
	//d2 += 100;
	//d2.print();
	cout << ( d1 -d2) << endl;
}
int main()
{
	DataTest();
}