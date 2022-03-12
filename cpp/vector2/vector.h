#pragma once
#include<assert.h>
#include<iostream>
//using namespace std;
namespace bit
{
	template <class T>
	class vector
	{ 
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() { return _start;}
		
		iterator end() { return _start + size(); }
		const_iterator begin() const { return _start; }
		const_iterator end() const { return _start + size(); }
		bool empty() const { return size() == 0; }
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)   //提供一个有迭代器区间的构造函数
			:_start(nullptr)
			, _finsh(nullptr)
			, _endofstacoe(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector()
			:_start(nullptr)
			,_finsh(nullptr)
			, _endofstacoe(nullptr)
		{

		}
		//vector(const vector<T>& v)   // 传统写法
		//{
		//	_start = new T[v._capatity];
		//	_finish = _start + v.size();
		//	_endofstorage = _start + v.capacity();
		//	for (int i = 0; i < size(); ++i)
		//	{
		//		_start[i] = v._start[i];
		//	}
		//}
		void swap(vector<T> & v)
		{
			std::swap(_start, v._start);
			std::swap(_finsh,v._finsh);
			std::swap(_endofstacoe, v._endofstacoe);
		}
		vector(const vector<T>& v)  //现代写法
			:_start(nullptr)
			, _finsh(nullptr)
			, _endofstacoe(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}
		vector<T>& operator=( vector<T> v)  //现代写法
		{
			swap(v);
			return *this;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}
		const T& operator[](size_t pos) const 
		{
			assert(pos < size());
			return *(_start + pos);
		}
		size_t size() const
		{
			return _finsh - _start;
		}
		size_t capatity()
		{
			return _endofstacoe - _start;
		}
		void resize(size_t n, const T & v = T())
		{
			if (n <= size())
			{
				_finsh = _start + n;
				return;
			}
			else
			{
				if (n > capatity())
				{
					reserve(n);
					iterator it = _finsh;
					_finsh = _start + n;
					while (it != _finsh)
					{
						*it = v;
						++it;
					}
				}
			}
		}
		void reserve(size_t n)
		{
			if (n > capatity())
			{
				size_t ze = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (int i = 0; i < ze; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[]_start;
				}
					_start = tmp;
					_finsh = _start + ze;
					_endofstacoe = _start + n;
			}
		}
		void push_back(const T& val = T())
		{
			if (_finsh == _endofstacoe)
			{
				reserve(capatity() == 0 ? 4 : 2 * capatity());
			}
			*_finsh++ = val;
		}
		void pop_back()
		{
			assert(_start != _finsh);
			--_finsh;
		}
		iterator insert(iterator pos,const T& v)
		{
			assert(pos >= _start);	
			assert(pos <= _finsh);
			if (_finsh == _endofstacoe)
			{
				size_t len = pos - _start;   //需要记录pos相对位置，不然扩容后迭代器会失效
				reserve(capatity() == 0 ? 4 : 2 * capatity());
				pos = _start + len;
			}
			iterator end = _finsh - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = v;
			++_finsh;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finsh);
			iterator begin = pos + 1;
			while (begin < _finsh)
			{
				*(begin - 1) = *(begin);
				++begin;
			}
			--_finsh;
			return pos;
		}
		~vector()
		{
			_start = _finsh = _endofstacoe = nullptr;
		}
	private:
		T* _start;
		T* _finsh;
		T* _endofstacoe;
	};

	void vector_test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.insert(v.begin(), 10);
		v.insert(v.begin(), 10);
		v.insert(v.begin(), 10);
		v.insert(v.begin(), 10);
		v.insert(v.begin(), 10);
		v.erase(v.end() - 1);
	/*	v.erase(v.end() - 1);
		v.erase(v.end() - 1);*/
	/*	vector<std::string> v;
		v.push_back("1111111");
		v.push_back("1111111");
		v.push_back("1111111");
		v.push_back("1111111");
		v.push_back("1111111");*/
		//v.pop_back();
		//v.pop_back();
		//v.pop_back();
		//v.pop_back();
		//v.pop_back();
		vector<int> v1 = v;
		for (auto e : v1)
		{
			std:: cout << e << " ";
		}
		std::cout << std::endl;
	}
}
