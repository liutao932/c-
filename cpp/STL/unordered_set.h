#pragma once
#include"Hash.hpp"

namespace OpenHash
{
	template<class K, class hash = Hash<K>>
	class unordered_set
	{
	public:
		class SetOfT
		{
		public:
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		typedef typename HashTable<K, K, SetOfT, hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		std::pair<iterator,bool> insert(const K& key)
		{
			return _ht.insert(key);
		}
		bool earse(const K& key)
		{
			return _ht.erase();
		}
		iterator find(const K& key)
		{
			return _ht.find(key);
		}

	private:
		HashTable<K, K,SetOfT, hash> _ht;
	};
	void test_unordered_set()
	{
		unordered_set<int> us;
		us.insert(4);
		us.insert(14);
		us.insert(34);
		us.insert(7);
		us.insert(24);
		us.insert(17);
		us.insert(1);
		/*unordered_set < std::string> us;
		us.insert("sort");
		us.insert("map");
		us.insert("left");
		us.insert("right");
		us.insert("apples");*/
		for (const auto e : us)
		{
			std::cout << e << std::endl;
		}
	}
}
