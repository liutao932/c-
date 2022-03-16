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
		iterator end() { return _finsh; }
		const_iterator begin()const  { return _start; }
		const_iterator end()const  { return _finsh; }
		size_t size()const { return _finsh - _start; }
		size_t capatity()const { return _endfstaoce - _start; }
		size_t empty()const { return size() == 0; }
		vector()
			:_start(nullptr)
			, _finsh(nullptr)
			, _endfstaoce(nullptr)
		{

		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
				:_start(nullptr)
				, _finsh(nullptr)
				, _endfstaoce(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finsh, v._finsh);
			std::swap(_endfstaoce, v._endfstaoce);
		}
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finsh(nullptr)
			, _endfstaoce(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		void reserve(size_t n)
		{
			if (n > capatity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					for (size_t i = 0; i < size(); ++i)
					{
						tmp[i] = _start[i];
					}
					delete[]_start;
				}
				_start = tmp;
				_finsh = _start + sz;
				_endfstaoce = _start + n;

			}
		}
		void resize(size_t n,const T&val = T())
		{
			if (n < size())
			{
				_finsh = _start + n;
			}
			else
			{
				if (n > capatity())
				{
					reserve(n);
				}
				iterator it = _finsh;
				_finsh = _start + n;
				while (it != _finsh)
				{
					*it = val;
					++it;
				}
			}
		}
		void push_back(const T& val = T())
		{
			if (_finsh == _endfstaoce)
			{
				reserve(capatity() == 0 ? 4 : 2 * capatity());
			}
			*_finsh = val;
			++_finsh;
		}
		void pop_back()
		{
			assert(!empty());
			--_finsh;
		}
		void clear()
		{
			_finsh = _start;
		}
		iterator insert(iterator pos,const T& val)
		{
			assert(pos >=_start &&	pos < _finsh);
			if (_finsh == _endfstaoce)
			{
				size_t len = pos - _start;
				reserve(capatity() == 0 ? 4 : 2 * capatity);
				pos = _start + pos;
			}
			*pos = val;
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
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}
		T& front()
		{
			return *_start;
		}
		T& back()
		{
			T* tmp = _finsh -1;
			return *tmp;
		}
		~vector()
		{
			_start = _finsh = _endfstaoce = nullptr;
		}
	private:
		T* _start;
		T* _finsh;
		T* _endfstaoce;
	};
	void vectortest1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		vector<int> v2(v1);
		vector<int> v3 = v2;
	/*	for (auto e : v3)
		{
			std::cout << e << " ";
		}*/
		std::cout << v3.front() << " " << v3.back() << std::endl;
		for (size_t i = 0; i < v3.size(); ++i)
		{
			std::cout << v3[i] << " ";
		}
		std::cout << std::endl;
	}
}