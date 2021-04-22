#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {

    }
    
    int get(int key) {
        auto it = table.find(key);
        if (it != table.end()) {
            lru.splice(lru.begin(), lru, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = table.find(key);
        if (it != table.end()) {
            it->second->second = value;
            lru.splice(lru.begin(), lru, it->second);
            return;
        }
        lru.emplace_front(key, value);
        table[key] = lru.begin();
        if (table.size() > capacity) {
            table.erase(lru.back().first);
            lru.pop_back();
        }
    }
private:
    int capacity;       // 内核·
    list<pair<int, int>> lru;   // 存放前后顺序访问
    unordered_map<int, list<pair<int, int>>::iterator> table;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */