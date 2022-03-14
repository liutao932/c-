#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
#include<assert.h>
namespace bit
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
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capatity, s._capatity);
		}
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
			, _size(strlen(str))
			, _capatity(_size)
		{
			strcpy(_str, str);
		}
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capatity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		string& operator+=(char x)
		{
			push_back(x);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void reserve(size_t n)
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
		void resize(size_t n, char x = '\0')
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
					reserve(n);
				}
				memset(_str + _size, x, n - _size);		
				_str[n] = '\0';
				_size = n;
			}
		}
		void push_back(char x)
		{
			if (_size == _capatity)
			{
				reserve(_capatity == 0 ? 4: 2* _capatity);
			}
			_str[_size++] = x;
			_str[_size] = '\0';
		}
		void pop_back()
		{
			assert(size() > 0);
			_size--;
		}
		void append(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capatity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size = _size + len;
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capatity)
			{
				reserve(_capatity == 0 ? 4 : 2 * _capatity);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			int len = strlen(str);
			if (_size + len > _capatity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end > pos)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		size_t find(const char ch) const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		char& operator[](size_t pos)const { assert(pos >= 0 && pos < _size);  return *(_str + pos); }
		char* c_str() const { return _str; }
		size_t size() const { return _size; }
		~string()
		{
			delete[]_str;
			_size = _capatity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capatity;
		static  size_t npos;
	};	
    size_t string::npos = -1;
	void stringtest1()
	{
		string s;
		s.push_back('a');
		s.push_back('b');
		s.push_back('c');
		s.push_back('d');
		/*s += 'e';
		s += "my love";
		s.insert(0, 'x');
		s.resize(100);*/
		s.insert(0, "my love");
		/*for (size_t i = 0; i < s.size(); ++i)
		{
			std::cout << s[i] << " ";
		}*/
		for (auto e : s)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
		std::cout << s.find('l') << std::endl;

	}
}