#include<iostream>
#include<assert.h>

template <class K, class V>
class AVLTreeNode
{
public:
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	std::pair<K, V> _kv;
	AVLTreeNode(const std::pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{
		
	}
};
template<class K,class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;
	AVLTree()
		:_root(nullptr)
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
		while (cur != nullptr)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
			cur = new Node(kv);
			if (kv.first > parent->_kv.first)
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
				
			//更新平衡因子
			while (parent != nullptr)
			{
				if (cur == parent->_left)
					parent->_bf--;
				else
					parent->_bf++;

				if (parent->_bf == 0)  //不用更新
				{
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)  //继续往上更新
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if(parent->_bf == 2 || parent->_bf == -2) //旋转
				{
					if (parent->_bf == 2 && cur->_bf == 1) //左单旋
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1) //右单旋
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1) //右左双旋
					{
						RotateRL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1) //左右双旋
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
			}
		return true;
	}
private:
	void RotateL(Node* parent)  //左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* parentparent = parent->_parent;

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subRL;
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
				parentparent->_right = subR;
			subR->_parent = parentparent;
		}
		subR->_bf = parent->_bf = 0;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
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
			subL->_parent = parentparent;
		}
		subL->_bf = parent->_bf = 0;
	}
	void RotateRL(Node* parent)
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
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateLR(Node* parent)
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
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
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
					MostRight->_right = cur;
				}
			}
			std::cout << cur->_kv.first << ":" << cur->_kv.second << std::endl;
			cur = cur->_right;
		}
	}
private:
	Node* _root;
};

