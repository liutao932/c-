#pragma once
#include<iostream>
namespace bit
{
	template<class T>
	struct __list_node
	{
		__list_node(const T& data = T())
			:prev(nullptr)
			,next(nullptr)
			,_data(data)
		{

		}
		__list_node<T>* prev;
		__list_node<T>* next;
		T _data;
	};
	template<class T,class pef,class ptr> //封装自定义类型的指针成迭代器，强类型，通过重载运算符使用
	class list_iterator
	{
	public:
		typedef __list_node<T> Node;
		typedef const list_iterator<T,pef,ptr> self;   //通过模板参数可以解决const对象的迭代器的使用，解决代码的冗余
		list_iterator(Node* node = nullptr):_node(node){ }


		bool operator!=(self& val) { return _node != val._node; }
		bool operator==(self& val) { return _node == val._node; }
		pef& operator*() { return _node->_data; }
		ptr* operator->() { return &_node->data; }
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		self& operator++(int)
		{
			list_iterator<T> tmp(*this);
			_node = _node->next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->prev;
			return *this;
		}
		self& operator--(int)
		{
			list_iterator<T> tmp(*this);
			_node = _node->prev;
			return tmp;
		}
		Node* _node;
	};
	template<class T>
	class list
	{
	public:
		typedef __list_node<T>  Node;
		typedef  list_iterator<T, T&, T*> iterator;
		typedef  list_iterator<T, const T&, const T*> const_iterator;
		iterator begin() { return iterator(_head->next); }
		iterator end() { return iterator(_head); }
		const_iterator begin()const  { return iterator(_head->next); }
		const_iterator end()const  { return iterator(_head); }
		list()
			:_head(new Node)
		{
			_head->next = _head;
			_head->prev = _head;
		}
		void push_back(const T & val)
		{

			Node* newnode = new Node(val);
			Node* tail = _head->prev;
			tail->next = newnode;
			newnode->prev = tail;
			newnode->next = _head;
			_head->prev = newnode;
		}
	private:
		Node* _head;
	};
	void listtest()
	{
		list<int>lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
}