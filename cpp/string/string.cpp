#include"string.h"
//using namespace bit;
using namespace mystring;
void test(void)
{
    string s1("hello world");
	//string s1(s);
	string s2(s1);
	/*string s3 = s1;
	s3 = s3;*/
	string s3("sort");
	s1 = s3;
	s3 = s3;
}
void test1(void)
{
	/*std::string s;
	std::cout << s.c_str() << std::endl;
	string s1;
	std::cout << s1.c_str() << std::endl;*/
	string s1("hello world");
	std::cout << s1.size() << std::endl;
	std::cout << s1.c_str() << std::endl;
	for (int i = 0; i < s1.size(); ++i)
	{
		s1[i]++;
		s1[i]--;
		std::cout << s1[i] << " ";
	}
	const string s2("hello");
	for (int i = 0; i < s2.size(); ++i)
	{
		/*s2[i]++;
		s2[i]--;*/
		std::cout << s2[i] << " ";
	}
	string::iterator it = s1.begin();
	std::cout << std::endl;
	while (it != s1.end())
	{
		std::cout << *it << " ";
		it++;
	}
}
int main()
{
	//test();
	test1();
}
