#pragma once
#include<iostream>
namespace bit
{
	template<class T>
	struct _list_node
	{
		_list_node(const T&val = T())
			:_next(nullptr)
			,_prev(nullptr)
			, _val(val)
		{

		}
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _val;
	};
	template<class T, class pef, class ptr> //封装自定义类型的指针成迭代器，强类型，通过重载运算符使用
	class list_iterator
	{
	public:
		typedef _list_node<T> Node;
		typedef list_iterator<T, pef, ptr> self;   //通过模板参数可以解决const对象的迭代器的使用，解决代码的冗余
		list_iterator(Node* node = nullptr) :_node(node) { }


		bool operator!=(const self& val) { return _node != val._node; }
		bool operator==(const self& val) { return _node != val._node; }
		pef& operator*() { return _node->_val; }
		ptr* operator->() { return &_node->_val; }
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->prev;
			return tmp;
		}
		Node* _node;
	};
	template<class T>
	class list
	{
	public:
		typedef _list_node<T> Node;
		typedef  list_iterator<T, T&, T*> iterator;
		typedef  list_iterator<const T, const T&, const T*> const_iterator;
		iterator begin() { return iterator(_head->_next); }
		iterator end() { return iterator(_head); }
		const_iterator begin()const { return const_iterator(_head->next); }
		const_iterator end()const { return const_iterator(_head); }


		size_t size()
		{
			iterator it = begin();
			int count = 0;
			while (it != end())
			{
				++count;
				++it;
			}
			return count;
		}
		bool empty()
		{
			return _head->_next == _head;
		}
		T& front()const
		{
			return _head->_next->_val;
		}
		T& back()const
		{
			return _head->_prev->_val;
		}
		template<class iterator>
		list(iterator first, iterator last)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(list<T>& val)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			list<T>tmp(val.begin(), val.end());
			std::swap(_head, tmp._head);
		}
		list<T>& operator=(list<T> val)
		{
			std::swap(_head, val._head);
			return *this;
		}
		void push_back(const T & val)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(val);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			insert(end(), val);
		}
		void pop_back(const T& val)
		{
			insert(begin(), val);
		}
		void pop_front()
		{
			erase(begin());
		}
		void pop_back()
		{
			erase(--end());
		}
		void resize(size_t n, const T& v = T())
		{
			size_t sz = size();
			for (size_t i = 0; i < n - sz ; ++i)
			{
				push_back(v);
			}
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			delete pos._node;
			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	private:
		Node* _head;
	};
	void listest1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		list<int>l2(l1);
		list<int>l3 = l2;
		//l3.clear();
		//std::cout << l3.size() << std::endl;
		//std::cout << l3.front() <<std::endl;
		//std::cout << l3.back() << std::endl;
		//l3.pop_front();
		//l3.pop_back();
		std::cout << l3.size() << std::endl;
		l3.resize(10,1);
		std::cout << l3.size() << std::endl;
		list<int>::iterator it = l3.begin();
		while (it != l3.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
}