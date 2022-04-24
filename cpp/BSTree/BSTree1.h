#pragma once
#include<iostream>
#include<stack>

//namespace MySTL
//{
//	template<class K>
//	struct BrainryTreeNode
//	{
//		BrainryTreeNode(const K & key = K())
//			:_left(nullptr)
//			,_right(nullptr)
//			,_key(key)
//		{
//
//		}
//		BrainryTreeNode<K>* _left;
//		BrainryTreeNode<K>* _right;
//		K _key;
//	};
//
//	template<class K>
//	class BSTree
//	{
//	public:
//		typedef BrainryTreeNode<K> Node;
//		BSTree()
//			:_root(nullptr)
//		{
//
//		}
//		//非递归
//		bool insert(const K& key)
//		{
//			if (_root == nullptr)
//			{ 
//				_root = new Node(key);
//				return true;
//			}
//			Node* parent = nullptr;
//			Node* cur = _root;
//			while (cur != nullptr)
//			{
//				if (key > cur->_key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (key < cur->_key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return false;
//				}
//			}
//			if (key > parent->_key)
//			{
//				parent->_right = new Node(key);
//			}
//			else
//			{
//				parent->_left = new Node(key);
//			}
//			return true;
//		}
//		bool find(const K& key)
//		{
//			Node* cur = _root;
//			while (cur != nullptr)
//			{
//				if (key > cur->_key)
//				{
//					cur = cur->_right;
//				}
//				else if (key < cur->_key)
//				{
//					cur = cur->_left;
//				}
//				else
//				{
//					return true;
//				}
//			}
//			return false;
//		}
//		bool erase(const K& key)
//		{
//			Node* cur = _root;
//			Node* parent = nullptr;
//			while (cur != nullptr)
//			{
//				if (key > cur->_key)
//				{
//					cur = cur->_right;
//				}
//				else if(key < cur->_key)
//				{
//					cur = cur->_left;
//				}
//				else //找到了
// 				{
//					if (cur->_left == nullptr)   //左为空
//					{
//						if (parent == nullptr)
//						{
//							_root = _root->_right;
//							return true;
//						}
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//						delete cur;
//					}
//					else if (cur->_right == nullptr) //右为空
//					{
//						if (parent == nullptr)
//						{
//							_root = _root->_left;
//							return true;
//						}
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_left;
//						}
//						else
//						{
//							parent->_right = cur->_left;
//						}
//						delete cur;
//					}
//					else  //左右都不为空
//					{
//						Node* min = cur->_right;
//						Node* minparent = cur;
//						while (min->_left != nullptr)
//						{
//							minparent = min;
//							min = min->_left;
//						}
//						cur->_key = min->_key;
//
//						if (minparent->_left == min)
//							minparent->_left = min->_right;
//						else
//							minparent->_right = min->_right;
//						delete min;
//					}
//					return true;
//				}
//			}
//			return false;
//		}
//		void inoder()   //中序遍历
//		{
//			/*
//			Node* cur = _root;
//			Node* MostRight = nullptr;
//			while (cur != nullptr)
//			{
//				MostRight = cur->_left;
//				if (MostRight != nullptr)
//				{
//					while (MostRight->_right != nullptr && MostRight->_right != cur)
//					{
//						MostRight = MostRight->_right;
//					}
//					if (MostRight->_right == nullptr)
//					{
//						MostRight->_right = cur;
//						cur = cur->_left;
//						continue;
//					}
//					else
//					{
//						MostRight->_right = nullptr;
//					}
//				}
//				std::cout << cur->_key << " ";
//				cur = cur->_right;
//			}
//			std::cout << std::endl;
//			*/
//			std::stack<Node*> st;
//			Node* cur = _root;
//			while (!st.empty() || cur != nullptr)
//			{
//				if (cur != nullptr)
//				{
//					st.push(cur);
//					cur = cur->_left;
//				}
//				else
//				{
//					cur = st.top();
//					st.pop();
//					std::cout << cur->_key << " ";
//					cur = cur->_right;
//				}
//			}
//			std::cout << std::endl;
//		}
//
//		bool findR(const K& key)
//		{
//			return _findR(_root,key);
//		}
//		bool insertR(const K& key)
//		{
//			return _insertR(_root,key);
//		}
//		bool eraseR(const K& key)
//		{
//			return _eraseR(_root, key);
//		}
//		void inoderR()
//		{
//			_inoderR(_root);
//			std::cout << std::endl;
//		}
//	private:
//		bool _findR(Node* root,const K& key)
//		{
//			if (root == nullptr)
//				return false;
//			if (key > root->_key)
//			{
//				return _findR(root->_right, key);
//			}
//			else if (key < root->_key)
//			{
//				return _findR(root->_left, key);
//			}
//			else
//			{
//				return true;
//			}
//		}
//		bool _insertR(Node* &root,const K& key)
//		{
//			if (root == nullptr)
//			{
//				root = new Node(key);
//				return true;
//			}
//			if (key > root->_key)
//				return _insertR(root->_right, key);
//			else if (key < root->_key)
//				return _insertR(root->_left, key);
//			else
//				return false;
//		}
//
//		bool _eraseR(Node*& root, const K& key)
//		{
//			if (root == nullptr)
//				return false;
//			if (key > root->_key)
//			{
//				return _eraseR(root->_right, key);
//			}
//			else if (key < root->_key)
//			{
//				return _eraseR(root->_left, key);
//			}
//			else  //找到了
//			{
//				Node* del = root;
//				if (root->_left == nullptr)
//					root = root->_right;
//				else if (root->_right == nullptr)
//					root = root->_left;
//				else
//				{
//					Node* min = root->_right;
//					while (min->_left != nullptr)
//					{
//						min = min->_left;
//					}
//					std::swap(min->_key, root->_key);
//					
//					return _eraseR(root->_right, key);
//				}
//				delete del;
//				return true;
//			}
//		}
//		void _inoderR(Node* root)
//		{
//			if (root == nullptr)
//				return;
//			_inoderR(root->_left);
//			std::cout << root->_key << " ";
//			_inoderR(root->_right);
//		}
//	private:
//		Node* _root;
//	};
//
//
//	/*
//	void BSTreeTest()
//	{
//		BSTree<int> bt;
//		int array[] = { 9,7,5,3,4,1,2,0 };
//		for (auto e : array)
//		{
//			bt.insert(e);
//		}
//		//bt.inoder();
//		//std::cout << bt.find(8) << std::endl;
//		for (auto e : array)
//		{
//			bt.erase(e);
//			bt.inoder();
//		}
//	}
//	*/
//	void BSTreeTest()
//	{
//		BSTree<int> bt;
//		int array[] = { 9,7,5,3,4,1,2,0 };
//		for (auto e : array)
//		{
//			bt.insert(e);
//		}
//		//bt.inoderR();
//		//std::cout << bt.findR(10) << std::endl;
//		for (auto e : array)
//		{
//			bt.erase(e);
//			bt.inoder();
//		}
//	}
//}

namespace MySTL
{
	template<class K,class V>
	struct BrainryTreeNode
	{
		BrainryTreeNode(const K& key = K(),const V& val = V())
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_val(val)
		{

		}
		BrainryTreeNode<K,V>* _left;
		BrainryTreeNode<K,V>* _right;
		K _key;
		V _val;
	};
	template<class K,class V>
	class BSTree
	{
	public:
		typedef BrainryTreeNode<K, V> Node;
		BSTree()
			:_root(nullptr)
		{

		}
		//非递归
		bool insert(const K& key,const V& val)
		{
			if (_root == nullptr)
			{
				_root = new Node(key,val);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			if (key > parent->_key)
			{
				parent->_right = new Node(key, val);
			}
			else
			{
				parent->_left = new Node(key, val);
			}
			return true;
		}
		Node* find(const K& key)
		{
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}
		bool erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else //找到了
				{
					if (cur->_left == nullptr)   //左为空
					{
						if (parent == nullptr)
						{
							_root = _root->_right;
							return true;
						}
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr) //右为空
					{
						if (parent == nullptr)
						{
							_root = _root->_left;
							return true;
						}
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
						delete cur;
					}
					else  //左右都不为空
					{
						Node* min = cur->_right;
						Node* minparent = cur;
						while (min->_left != nullptr)
						{
							minparent = min;
							min = min->_left;
						}
						cur->_key = min->_key;
						cur->_val = min->_val;

						if (minparent->_left == min)
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
		void inoder()   //中序遍历
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
				std::cout << cur->_key <<":"<<cur->_val<<std::endl;
				cur = cur->_right;
			}
			std::cout << std::endl;;
		}
		private:
			Node* _root;
	};


	//void Test1()
	//{
	//	BSTree<std::string, std::string> bt;
	//	bt.insert("joke", "123");
	//	bt.insert("mike", "234");
	//	bt.insert("kebi", "345");
	//	bt.insert("zhanmusi", "678");
	//	bt.insert("aoni", "000");
	//	bt.inoder();
	//	std::cout << bt.find("kebi")->_val<< std::endl;
	//}
	void Test2()
	{
		BSTree<std::string, int> bt;
		std::string s[] = { "ABC","ABC","ABC","abc","abc","EDF","edf" };
		for (auto e : s)
		{
			auto ret = bt.find(e);
			if (ret)
			{
				ret->_val++;
			}
			else
			{
				bt.insert(e, 1);
			}
		}
		bt.inoder();
	}
}
