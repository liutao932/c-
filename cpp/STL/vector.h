#pragma once
#include<iostream>
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() { return _start; }
		iterator end() { return _start + size(); }
		const_iterator begin()const  { return _start; }
		const_iterator end() const { return _finsh; }
		size_t size()const { return _finsh - _start; }
		size_t capatity()const { return _endofstaoce - _start; }
		bool  empty() const { return size() == 0; }
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
		template <class InputIterator>  //IO迭代器
		vector(InputIterator first, InputIterator last)   //提供一个有迭代器区间的构造函数
			:_start(nullptr)
			, _finsh(nullptr)
			, _endofstaoce(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector()
			:_start(nullptr)
			, _finsh(nullptr)
			, _endofstaoce(nullptr)
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
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finsh, v._finsh);
			std::swap(_endofstaoce, v._endofstaoce);
		}
		vector(const vector<T>& v)  //现代写法
			:_start(nullptr)
			, _finsh(nullptr)
			, _endofstaoce(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}
		vector<T>& operator=(vector<T> v)  //现代写法
		{
			swap(v);
			return *this;
		}
		void reserve(size_t n)
		{
			if (n > capatity())
			{
				T* tmp = new T[n];
				size_t len = size();
				for (size_t i = 0; i < size(); ++i)
				{
					tmp[i] = _start[i];    //如果不是内置类型，进行深拷贝(辅助拷贝)
				}
				delete[] _start;

				_start = tmp;
				_finsh = _start + len;
				_endofstaoce = _start + n;
			}
		}
		void resize(size_t n, const T& v = T())
		{
			if (n < size())
			{
				_finsh -= n;
			}
			else
			{
				if (n > capatity)
				{
					reserve(n);
				}
				iterator it = _finsh;
				_finsh = _start + n;
				while (it != _finsh)
				{
					*it = v;
					++it;
				}
			}
		}
		void push_back(const T& v)
		{
			if (_finsh == _endofstaoce)
			{
				reserve(capatity() == 0 ? 4 : 2 * capatity());
			}
			*_finsh = v;
			++_finsh;
		}
		iterator insert(iterator pos, const T& v)
		{
			assert(pos >= _start && pos < _finsh);
			if (_finsh == _endofstaoce)
			{
				size_t len = pos - _start;
				reserve(capatity() == 0 ? 4 : 2 * capatity);
				pos = _start + len;
			}
			iterator end = _finsh + 1;
			while (end > pos)
			{
				*(end) = *(end - 1);
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
			while (begin != _finsh)
			{
				*(begin - 1) = *(begin);
				++begin;
			}
			--_finsh;
			return pos;
		}
		~vector()
		{
			delete[]_start;
			_start = _finsh = _endofstaoce = nullptr;
		}
	private:
		T* _start;
		T* _finsh;
		T* _endofstaoce;
	};
	void vectortest()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		vector<int> v1(v);
		vector<int> v2 = v1;
		for (auto e : v2)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}