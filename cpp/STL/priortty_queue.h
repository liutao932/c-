#pragma once
#include<iostream>
#include"vector.h"
#include<algorithm>
#include<vector>
#include"data.h"

namespace bit
{
	template <class T>
	struct Less  //防函数
	{
		bool operator()(const T &a, const T &b)const 
		{
			return a < b;
		}
	};
	template<>
	struct Less<Data*>
	{
		bool operator()(const Data* a, const  Data* b)const
		{
			return *a < *b;
		}
	};
	template <class T>
	struct Greater
	{
		bool operator()(const T& a, const T& b)const
		{
			return a > b;
		}
	};
	template<>
	struct Greater<Data*>
	{
		bool operator()(const Data* a, const  Data* b)const
		{
			return *a > *b;
		}
	};
	template <class T, class Container = vector<T>, class Compare = Less<T>> //默认Less是大堆
	class priorirty_queue
	{
	private:
		void AdJustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
			   if(com(_con[parent],_con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDown(int parent)
		{
			Compare com;
			int child = 2 * parent + 1;
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child] > _con[parent])
				if(child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}
				if (com(_con[parent],_con[child]))
			  //if(com(_con[child], _con[child + 1]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}
	public:
		priorirty_queue() :_con(){};
		template <class iterator>
		priorirty_queue(iterator frist, iterator last)
			:_con( frist, last)
		{
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				AdjustDown(i);
			}
		}
		void push(const T & val)
		{
			_con.push_back(val);
			AdJustUp(_con.size() -1);
		}
		void pop()
		{
			if (empty()) return;
			std::swap(_con.front(), _con.back());
			_con.pop_back();
			AdjustDown(0);
		}
		 T& top()
		{
			return _con.front();
		}
		bool empty() const 
		{
			return _con.empty();
		}
		size_t size() const 
		{
			_con.size();
		}
	private:
		Container _con;
	};


	void priority_queue_test()
	{
		//priorirty_queue<int> pq;
		//pq.push(1);
		//pq.push(2);
		//pq.push(9);
		//pq.push(3);
		//pq.push(5);
		priorirty_queue<Data*> pq;
		pq.push(new Data(2021, 4, 19));
		pq.push(new Data(2020, 4, 19));
		pq.push(new Data(2022, 4, 19));
		while (!pq.empty())
		{
			std::cout << *pq.top();
			pq.pop();
		}
	}
}