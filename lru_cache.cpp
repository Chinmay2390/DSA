// lru_cache.cpp - Implementation of LRU Cache using list and unordered_map
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;

        // Move accessed item to front
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Update and move to front
            map[key]->second = value;
            cache.splice(cache.begin(), cache, map[key]);
        } else {
            if (cache.size() == capacity) {
                // Remove LRU from back
                auto lru = cache.back();
                map.erase(lru.first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
};

// Sample driver code
int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;  // 1
    lru.put(3, 3);               // evicts key 2
    cout << lru.get(2) << endl;  // -1
    lru.put(4, 4);               // evicts key 1
    cout << lru.get(1) << endl;  // -1
    cout << lru.get(3) << endl;  // 3
    cout << lru.get(4) << endl;  // 4
    return 0;
}
