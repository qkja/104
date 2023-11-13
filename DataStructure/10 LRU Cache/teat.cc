#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key)
    {
        auto iter = _hashMap.find(key);
        if (iter == _hashMap.end())
            return -1;
        // 调整一下
        LtIter it = iter->second;
        _LRUList.splice(_LRUList.begin(), _LRUList, it);
        return it->second;
    }

    void put(int key, int value)
    {
        auto iter = _hashMap.find(key);
        if (iter == _hashMap.end())
        {
            // 新增
            if (_hashMap.size() == _capacity)
            {
                // 如果满了,删除数
                std::pair<int,int> back = _LRUList.back();
                _hashMap.erase(back.first);
                _LRUList.pop_back();
            }
            _LRUList.push_front(std::make_pair(key, value));
            _hashMap[key] = _LRUList.begin();
        }
        else
        {
            // 更新
            LtIter it = iter->second;
            it->second = value;
            _LRUList.splice(_LRUList.begin(), _LRUList, it);
        }
    }
private:
    std::size_t _capacity;
    typedef std::list<std::pair<int, int>>::iterator LtIter;
    std::list<std::pair<int, int>> _LRUList;
    std::unordered_map<int, LtIter> _hashMap;
};
