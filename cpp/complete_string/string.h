#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _STRING_
#define _STRING_
#include<iostream>
#include<string.h>
using namespace std;
#include<assert.h>
namespace BitString1 //传统写法
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

namespace BitString2  //现代写法
{

	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const 
		{
			return _str;
		}
		const_iterator end() const 
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			,_capatity(_size)
		{
			_str = new char[_capatity + 1];
			strcpy(_str, str);
		}
		void Swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capatity, s._capatity);
		}
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capatity(0)
		{
			string tmp(s._str);
			Swap(tmp);
		}
		string& operator=(string s)
		{
			Swap(s);
			return *this;
		}
		char* c_str() const
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return *(_str + pos);
		}
		const char& operator[](size_t pos)const 
		{
			assert(pos < _size);
			return *(_str + pos);
		}
		size_t size() const
		{
			return _size;
		}
		void reverse(size_t n)
		{
			if (n > _capatity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capatity = n;
			}
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capatity)
				{
					reverse(n);
				}
				memset(_str + _size, ch, n - _size);
				_str[n] = '\0';
				_size = n;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capatity)
			{
				reverse(_capatity == 0 ? 4 : 2 * _capatity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		size_t find(char ch)const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return n_pos;
		}
		const char* mystrstr(char* src, const char* dst) //BF算法
		{
			const char* begin = dst;
			char* prev = src, * cur = src;
			while (*cur != '\0' && *begin != '\0')
			{
				if (*cur == *begin)
				{
					cur++;
					begin++;
				}
				else
				{
					prev++;
					cur = prev;
					begin = dst;
				}
			}
			if (*begin == '\0')
				return prev;
			return nullptr;
			/*int lenstr = strlen(str);
			int lensub = strlen(sub);
			if (lenstr == 0 || lensub == 0) return nullptr;
			int strcur = 0;
			int strprev = 0;
			int subcur = 0;
			int subprev = 0;
			while (strprev < lenstr && subprev < lensub)
			{
				if (str[strprev] == sub[subprev])
				{
					strprev++;
					subprev++;
				}
				else
				{
					subprev = subcur;
					strcur++;
					strprev = strcur;
				}
			}
			if (sub[subprev] == '\0')
			{
				return &(str[strcur]);
			}
			return nullptr;*/
		}
		size_t find(const char* str,int pos = 0) 
		{
			//char * tmp = strstr(_str, str);
			const char* tmp = mystrstr(_str + pos, str);
			if (tmp == nullptr)
			{
				return n_pos;
			}
			return tmp - _str ;
		}
		size_t rfind(char ch) const 
		{
			char* begin = _str, *end = _str + _size;
			while (begin < end)
			{
				if (*end == ch)
				{
					return end - begin;
				}
				--end;
			}
			return n_pos;
		}
		string& insert(size_t pos,char ch)
		{
			if (_size == _capatity)
			{
				reverse(_size == 0 ? 4 : 2 * _capatity);
			}
			for (size_t i = _size + 1; i > pos; --i)
			{
				_str[i] = _str[i -1];
			}
			_str[pos] = ch;
			_size ++;
			return *this;
		}
		string& insert(size_t pos,const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capatity)
			{
				reverse(len + _size);
			}
			for (size_t i = _size + len; i > pos; --i)
			{
				_str[i] = _str[i - len];
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		string& insert(size_t pos ,const string& s)
		{
			size_t len = strlen(s._str);
			if (len + _size > _capatity)
			{
				reverse(len + _size);
			}
			for (size_t i = _size + len; i > pos; --i)
			{
				_str[i] = _str[i - len];
			}
			strncpy(_str + pos, s._str, len);
			_size += len;
			return *this;
		}
		string& erase(size_t pos = 0, size_t len = n_pos)
		{
			if (len >= _size || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capatity)
			{
				reverse(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(const string& s)
		{
			char* tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str);
			append(tmp);
			return *this;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capatity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capatity;
		static const size_t n_pos;
	};
	const size_t string::n_pos = -1;

	void StringTest1()
	{
	/*	string s1("hello world");
		cout << s1.c_str() << endl;
		string s2(s1);
		cout << s2.c_str() << endl;
		string s3 = s2;
		cout << s3.c_str() << endl;
		s3 = s3;
		cout << s2.c_str() << endl;*/
	/*	for (int i = 0; i < s3.size(); ++i)
		{
			cout << s3[i] << endl;
		}*/
		/*string::iterator it = s2.begin();*/
		/*while (it != s2.end())
		{
			cout << *it << endl;
			++it;
		}*/
		/*for (auto e : s2)
		{
			cout << e << endl;
		}*/
		/*for(int i = 0; i< 100;++i)
		s2.push_back('x');
		cout << s2.c_str() << endl;*/
		//s2 += 'x';
		//s2 += " my love";
	/*	s2 += s1;
		cout << s2.c_str() << endl;*/
		string s2;
		s2 += "x@sdadas";
		string s1("hello world");
		s2.insert(2, s1);
		//s2.resize(15,'a');
		/*s2.resize(100, 'x');
		cout << s2.c_str() << endl;*/
		cout << s2.c_str() << endl;
		/*cout << s2.find('@') << endl;
		cout << s2.rfind('@') << endl;
		cout << s2.find("as", 0) << endl;*/
		/*cout << s2.insert('!', 0).c_str() << endl;*/
	    //cout << s2.insert(0,"hello c++").c_str() << endl;
		//cout << s2.erase(2,8).c_str() << endl;
	}
}
#endif 

