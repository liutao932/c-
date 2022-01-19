#include"data.h"


void TestData(void)
{
	Data d1(2022, 1, 18);
	d1.print();
	Data d2(2021, 1, 18);
	d2.print();
	if (d1 > d2)
	{
		cout << "d1>d2" << endl;
	}
	else
	{
		cout <<"d1<d2" << endl;
	}
	//d1 -= 365;
	//d1.print();
	cout << (d1 - d2) << endl;
	cout << d1 << endl;
	cin >> d1;
	cout << d1;
}
int main()
{
	TestData();
}