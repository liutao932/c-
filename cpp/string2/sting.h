#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _STRING_
#define _STRING_
#include<iostream>
#include<string.h>
namespace BitString
{
	
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//s1("hello bit"); // s1;
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//s2(s1)
		string (const string& s)
			:_size(s._size)
			,_capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}
		//string s3("sort")  s3 = s1 , s3 = s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[]_str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		const size_t size()const
		{
			return _size;
		}
		char& operator[](int pos)
		{
			return _str[pos];
		}
		const char& operator[](int pos)const
		{
			return _str[pos];
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};


	void StringTest(void)
	{
		string s1;
		string s2("hello bit");
		string s3(s2);
		string s4("sort");
		s4 = s1;
		s4 = s4;
	}
	void StringTest1(void)
	{
		string s("hello bit");
		for (size_t i = 0; i < s.size(); ++i)
		{
			s[i]++;
			s[i]--;
			std::cout << s[i] << " ";
		}
		std::cout << std::endl;


		const string s1("hello c++");
		for (size_t i = 0; i < s1.size(); ++i)
		{
			//s1[i]++;
			std::cout << s1[i] << " ";
		}
		std::cout << std::endl;
	}
	void StringTest2(void)
	{
		string s("hello c++");
		string::iterator it = s.begin();
		while (it != s.end())
		{
			//(*it)++;
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		for (char e : s)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}
#endif // !_STRING_

