#pragma once
#include<iostream>
#include"list.h"

namespace bit
{
	template<class T , class Container = list<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
		T& front()
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
		
	private:
		Container _con;
	};
	void QueueTest()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);
		while (!q.empty())
		{
			std::cout << q.front() << " ";
			q.pop();
		}
	}
}