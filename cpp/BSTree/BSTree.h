#pragma once
#include<iostream>
using namespace std;

template<class K>
struct BrinaryTreeNode
{
	BrinaryTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, key(key)
	{}
	BrinaryTreeNode<K>* _left;
	BrinaryTreeNode<K>* _right;
	K key;
};
template<class K>
class BSTree
{
	typedef BrinaryTreeNode<K> Node;
private:
	Node* _find(Node* root, const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (key > root->key)
		{
			return _find(root->_right, key);
		}
		else if (key < root->key)
		{
			return _find(root->_left, key);
		}
		else
		{
			return root;
		}
	}
	bool _insertR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (key > root->key)
		{
			_insertR(root->_right, key);
		}
		else if (key < root->key)
		{
			_insertR(root->_left, key);
		}
		else
		{
			return false;
		}
	}
	bool _erase(Node*& root, const K& key)
	{
		if (root == nullptr)
			return false;
		if (key > root->key)
		{
			_erase(root->_right, key);
		}
		else if (key < root->key)
		{
			_erase(root->_left, key);
		}
		else
		{
			Node* del = root;
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				Node* min = root->_right;
				while (min)
				{
					min = min->_left;
				}
				if(min)
				swap(min->key, root->key);
				_erase(root->_right, key);
			}
			delete del;
			return true;
		}
	}
public:
	BSTree()
		:root(nullptr)
	{}

	void paint()   //morris遍历
	{
		Node* cur = root;
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
					MostRight->_right = nullptr;
			}
			cout << cur->key << " ";
			cur = cur->_right;
		}
	}
	bool insert(const K& key)  //插入
	{
		if (root == nullptr)  //如果根节点为空，那么就创建根
		{
			root = new Node(key);
			return true;
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		cur = new Node(key);
		if (key > parent->key)    //判断插入的节点在父亲的左边还是右边
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}
	bool insertR(const K& key)
	{
		return _insertR(root, key);
	}
	bool findR(const K& key)
	{
		return _find(root, key) == nullptr ? false : true;
	}
	bool eraseR(const K& key)
	{
		return _erase(root, key);
	}
	bool find(const K& key)
	{
		Node* cur = root;
		while (cur)
		{
			if (cur->key < key)
				cur = cur->_right;
			else if (cur->key > key)
				cur = cur->_left;
			else
				return true;
		}
		return false;
	}
	bool erase(const K& val)
	{
		Node* parent = nullptr;
		Node* cur = root;
		while (cur != nullptr)
		{
			if (cur->key < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->key > val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else  //找到了
			{
				if (cur->_left == nullptr)  //叶子节点和只有一个孩子的节点可以统一处理。
				{
					if (parent == nullptr)  //如果要删除的节点是根节点就让根节点右移
					{
						root = root->_right;
					}
					else
					{
						if (cur == parent->_left)   
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						root = root->_left;
					}
					else
					{
						if (cur == parent->_left)   
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
					delete cur;
				}
				else
				{
					Node* minparent = cur;    //这里是关键父亲给成 cur可以避免出现minparent是空的情况

					Node* min = cur->_right;
					while (min != nullptr)   //找到右子树最左节点
					{
						minparent = min;
						min = min->_left;
					}
					if(min)
					cur->key = min->key;   //替换法删除


					if (min->_left == minparent)
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
private:
	Node* root;
};
