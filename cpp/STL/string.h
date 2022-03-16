#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin() { return _str; }
		iterator end() { return _str + _size; }
		const_iterator begin()const  { return _str; }
		const_iterator end()const  { return _str + _size; }
		size_t size()const  { return _size; }
		size_t capatity()const { return _capatity; }
		static size_t max_size() { return npos; }
		bool empty()const { return size() == 0; }
		char* c_str()const { return _str; }
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
			, _size(strlen(str))
			, _capatity(_size)
		{
			strcpy(_str, str);
		}
		void swap(string& s)
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
			swap(tmp);
		}
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capatity = 0;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return *(_str + pos);
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return *(_str + pos);
		}
		void resize(size_t n, const char ch = '\0')
		{
			if (n < _size)
			{
				_str[_size] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capatity)
				{
					reserve(n);
				}
				memset(_str + _size, ch, n - _size);
				_str[_size] = '\0';
				_size = n;
			}
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
		void push_back(const char ch = char())
		{
			if (_size == _capatity)
			{
				reserve(_capatity == 0 ? 4 : 2 * _capatity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void pop_back()
		{
			assert(!empty());
			_str[--_size] = '\0';
		}
		void append(const char ch)
		{
			push_back(ch);
		}
		void append(const char* str)
		{
			int len = strlen(str);
			if (len + _size > _capatity)
			{
				reserve(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		void append(const string& s)
		{
			append(s._str);
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(const char ch)
		{
			push_back(ch);
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		string& insert(size_t pos,const char ch)
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
		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (pos + len > _size)
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
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0) const
		{
			char* tmp = strstr(_str, str);
			if (tmp == nullptr)
			{
				return npos;
			}
			else
			{
				return tmp - _str;
			}
		}
		
	private:
		char* _str;
		size_t _size;
		size_t _capatity;
		static size_t npos;
	};
	size_t string::npos = -1;


	void string_test1()
	{
		string s1("hello c++");
		string s2(s1);
		string s3 = s2;
		//s3.reserve(100);
		//s3.resize(100);
		//std::cout << s3.size() << std::endl;
		/*for (auto e : s2)
		{
			std::cout << e << " ";
		}*/
		/*s3.pop_back();
		s3.append("my love");
		s3.append(s1);
		s3.clear();*/
		//s3.insert(s3.size() -1, 'x');
		//s3.insert(1, "my love");
		//std::cout<<s3.max_size()<<std::endl;
		s3.erase(0,6);
		for (size_t i = 0; i < s3.size(); ++i)
		{
			std::cout << s3[i] << " ";
		}
		std::cout << std::endl;
	}
}
