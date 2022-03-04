#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void VectorTest1(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	/*vector<int>v1;
	v.swap(v1);*/
	/*vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		++it;
	}*/
	/*for (auto &e : v)
	{
		++ e;
		cout << e << endl;
	}*/
	//for (int i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << endl;
	//}
	vector<int>::iterator ret = find(v.begin(), v.end(), 3);
	//if (ret != v.end())
	//{
	//	cout << *ret << endl;
	//}
	v.insert(ret, 10);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	//cout << v << endl;
	//v.reserve(100);
	//v.resize(100, 0);
	//cout << v.empty() << endl;
}
int main()
{
	VectorTest1();
}
