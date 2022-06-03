#pragma once
#pragma once
#include"Hash.hpp"

namespace OpenHash
{
	template<class K,class V, class hash = Hash<K>>
	class unodered_map
	{
	public:
		class MapOfT
		{
		public:
			const K& operator()(const std::pair<K,V> & kv)
			{
				return kv.first;
			}
		};
		typedef typename HashTable<K, std::pair<K, V>, MapOfT, hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		std::pair<iterator,bool> insert(const std::pair<K, V>& kv)
		{
			return _ht.insert(kv);
		}
		iterator find(const K& key)
		{
			return _ht.find(key);
		}
		bool erase(const K& key)
		{
			return _ht.erase(key);
		}
	private:
		HashTable<K, std::pair<K,V>, MapOfT, hash> _ht;
	};
	void unordered_map_test()
	{
		/*unodered_map<int, int> um;
		um.insert(std::make_pair(1, 1));
		um.insert(std::make_pair(11, 11));
		um.insert(std::make_pair(21, 21));
		um.insert(std::make_pair(31, 31));
		um.insert(std::make_pair(41, 41));
		um.insert(std::make_pair(51, 51));*/

		unodered_map<std::string, std::string> um;
		um.insert(std::make_pair("sort", "排序"));
		um.insert(std::make_pair("map", "地图"));
		um.insert(std::make_pair("left", "左边"));
		um.insert(std::make_pair("right", "右边"));
		auto it = um.begin();
		while (it != um.end())
		{
			std::cout << it->first << ":" << it->second << std::endl;
			++it;
		}
		std::cout << std::endl;
		unodered_map < std::string, std::string > um2 = um;
		auto rit = um2.begin();
		while (rit != um2.end())
		{
			std::cout << rit->first << ":" << rit->second << std::endl;
			++rit;
		}
	}
}
