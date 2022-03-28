#include<iostream>
#include"vector.h"
namespace bit
{
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_back();
		}
		bool empty()
		{
			return _con.empty();
		}
		T& top()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};
	void TestStack()
	{
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		while (!st.empty())
		{
			std::cout << st.top() << " ";
			st.pop();
		}
		std::cout << std::endl;
	}
}