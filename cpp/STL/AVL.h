#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
#define NUM 0
template<class K, class V>
class AVLTreeNode
{
public:
	AVLTreeNode(const std::pair<K,V> kv = std::pair<K,V>())
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(NUM)
	{

	}
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	std::pair<K, V> _kv;
	int _bf; //balance number
};
template<class K,class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;
	AVLTree() :_root(nullptr)
	{

	}
	bool insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)   // 找到插入的位置
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//申请新节点插入在AVL中
		cur = new Node(kv);
		if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		//更新平衡因子
		while (parent != nullptr)
		{
			if (cur == parent->_right)  //比他大平衡因子加加
			{
				parent->_bf++;
			}
			else
			{ 
				parent->_bf--;   //比他小平衡因子减减
			}
			if (parent->_bf == 0)
			{
				break;        //不需要更新了，跳出循环
			}
			else if (parent->_bf == 1 || parent->_bf == -1)  //继续往上跟新
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) //旋转
			{
				if (parent->_bf == 2 && cur->_bf == 1) //右单旋
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1) //左单旋
				{
					RotateL(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)  //右左单旋(右单选 + 左单旋)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) //左右单旋(左单旋 + 右单旋）
				{
					RotateLR(parent);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
			return true;
		}
	}	
private:
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_left;
		Node* parentparent = parent->_parent;

		parent->_left = subLR;
		if (subLR != nullptr)
			subLR->_parent = parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentparent->_left == parent)
				parentparent->_left = subL;
			else
				parentparent->_right = subL;
		}
		subL->_bf = parent->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* parentparent = parent->_parent;

		parent->_right = subRL;
		if (subRL != nullptr)
		{
			subRL->_parent = parent;
		}
		parent->_parent = subR;
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentparent->_left == parent)
				parentparent->_left = subR;
			else
				parent->_right = subR;
		}
		subR->_bf = parent->_bf = 0;
	}
	void RotateRL(Node* parent)  //右单旋 + 左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 1)  //在右边插入
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1) //在左边插入
		{
			subR->_bf = 1;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateLR(Node* parent) //左单旋 + 右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 1)  //在右边插入
		{
			subL->_bf = -1;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == -1)  //在左边插入
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
public:
	void inoder()
	{
		std::stack<Node*> st;
		Node* cur = _root;
		while (cur != nullptr || !st.empty())
		{
			while (cur != nullptr)
			{
				st.push(cur);
				cur = cur->_left;
			}
			Node* top = st.top();
			std::cout << top->_kv.first << ":" << top->_kv.second << std::endl;
			st.pop();
			cur = top->_right;
		}
		/*
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
			std::cout << cur->_kv.first << ":" << cur->_kv.second << std::endl;
			cur = cur->_right;
		}
		*/
	}
private:
	Node* _root;
};
