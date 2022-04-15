#pragma once
#include<iostream>
using namespace std;

template <class K>
class BSTreeNode
{
public:
	BSTreeNode(const K& val)
		:_left(nullptr)
		, _right(nullptr)
		, _val(val)
	{

	}
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _val;
};

template <class K>
class BSTree
{

public:
	typedef BSTreeNode<K> Node;
	BSTree() :_root(nullptr) {};
	bool insert(const K& val)   //插入
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur != nullptr)
		{
			if (val > cur->_val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (val < cur->_val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		if (val > parent->_val)
			parent->_right = new Node(val);
		else
			parent->_left = new Node(val);
		return true;
	}
	bool find(const K& val)  //查找
	{
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (val > cur->_val)
				cur = cur->_right;
			else if (val < cur->_val)
				cur = cur->_left;
			else
				return true;
		}
		return false;
	}
	bool erase(const K& val) //删除
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur != nullptr)
		{
			if (val > cur->_val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (val < cur->_val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else    //找到要删除的节点
			{
				//叶子节点和只有一个节点的可以统一处理
				if (cur->_left == nullptr)
				{
					//这里要判断删除的是不是跟节点，当cur == root时,parent == nullptr
					if (parent == nullptr)
						_root = _root ->_right;
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}
					delete cur;
				}
				else if(cur->_right == nullptr)
				{
					if (parent == nullptr)
						_root = _root ->_left;
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
					delete cur;
				}
				else
				{
					Node* minparent = cur;   //防止minparent出现空的情况
					Node* min = cur->_right;
					while (min->_left != nullptr)
					{
						minparent = min;
						min = min->_left;
					}
	
					cur->_val = min->_val;

					if(minparent->_left == min)
						minparent->_left = min->_right;
					else
						minparent->_right = min->_right;
					delete min;
				}
				return true;
			}
		}
		return false;
	}
protected:
	bool _findR(Node* root, const K& val)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (val > root->_val)
		{
			_findR(root->_right, val);
		}
		else if (val < root->_val)
		{
			_findR(root->_left, val);
		}
		else
		{
			return true;
		}
	}
	bool _insertR(Node*& root, const K& val)
	{
		if (root == nullptr)
		{
			root = new Node(val);
			return true;
		}
		if (val > root->_val)
		{
			_insertR(root->_right, val);
		}
		else if (val < root->_val)
		{
			_insertR(root->_left, val);
		}
		else
		{
			return false;
		}
	}
	bool _eraseR(Node*& root, const K& val)
	{
		if (root == nullptr)
			return false;

		if (val > root->_val)
			_eraseR(root->_right, val);

		else if (val < root->_val)
			_eraseR(root->_left, val);

		else
		{
			Node* del = root;
			if (root->_left == nullptr)
				root = root->_right;
			else if (root->_right == nullptr)
				root = root->_left;
			else
			{
				Node* min = root->_right;
				while (min->_left != nullptr)
				{
					min = min->_left;
				}

				swap(min->_val, root->_val);
				_eraseR(root->_right, val);
			}
			delete del;
			return true;
		}
	}
public:
	bool findR(const K& val)
	{
		return _findR(_root, val);
	}
	bool insertR(const K& val)
	{
		return _insertR(_root, val);
	}
	bool eraseR(const K& val)
	{
		return _eraseR(_root, val);
	}
	/*void print()  //遍历
	{
		Node* cur = _root;
		Node* MostRight = nullptr;
		while (cur != nullptr)
		{
			MostRight = cur->_left;
			if (MostRight != nullptr)
			{
				while (MostRight->_right != nullptr && MostRight->_right != cur)
				{
					MostRight = MostRight->_right;
				}
				if (MostRight->_right == nullptr)
				{
					MostRight->_right = cur;
					cur = cur->_left;
					continue;
				}
				else
				{
					MostRight->_right = nullptr;
				}
			}
			cout << cur->_val << " ";
			cur = cur->_right;
		}
		cout << endl;
	}
	*/
	void _print(Node* root)
	{
		if (root == nullptr)
			return;
		_print(root->_left);
		cout << root->_val << " ";
		_print(root->_right);
	}
	void print()
	{
		_print(_root);
		cout << endl;
	}
private:
	Node* _root;
};

	int array[] = { 1,5,6,7,9,8,4,3,2 };

