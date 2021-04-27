#include <list>
#include <unordered_map>
using namespace std;

class LRUcache {
private:
    int capacity;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> table;
public:
    LRUcache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = table.find(key);
        if (it != table.end()) {
            lru.splice(lru.begin(), lru, it->second);
            return it->second->second;
        }

        return -1;
    }

    void put(int key, int val) {
        auto it = table.find(key);
        if (it != table.end()) {
            it->second->second = val;
            lru.splice(lru.begin(), lru, it->second);
            return;
        }

        lru.emplace_front(key, val);
        table[key] = lru.begin();
        if (lru.size() > capacity) {
            table.erase(lru.back().first);
            lru.pop_back();
        }
    }
};