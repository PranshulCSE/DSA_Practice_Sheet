/*
    Problem: LRU Cache
    -----------------------------
    Design a Least Recently Used (LRU) cache with fixed 
    capacity supporting get(key) and put(key, value) in 
    O(1) time. When capacity is exceeded, evict the least 
    recently used item.

    Example:
    LRUCache cache(2);
    cache.put(1,1); cache.put(2,2);
    cache.get(1);      // returns 1
    cache.put(3,3);    // evicts key 2
    cache.get(2);      // returns -1
    cache.put(4,4);    // evicts key 1
    cache.get(1);      // returns -1
    cache.get(3);      // returns 3
    cache.get(4);      // returns 4
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> map; // key -> node
    Node* dummyHead; // sबसे aage (most recently used side)
    Node* dummyTail; // sबसे peeche (least recently used side)

    // node ko uske current position se hata do
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // node ko dummyHead ke turant baad daal do (most recent position)
    void insertAtFront(Node* node){
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next->prev = node;
        dummyHead->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        dummyHead = new Node(-1, -1);
        dummyTail = new Node(-1, -1);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    int get(int key) {
        if(map.find(key) == map.end()){
            return -1; // key nahi mili
        }

        Node* node = map[key];
        removeNode(node);       // purani position se hataओ
        insertAtFront(node);    // most recently used bana do

        return node->value;
    }

    void put(int key, int value) {
        // agar key already hai, purana node hata do
        if(map.find(key) != map.end()){
            Node* oldNode = map[key];
            removeNode(oldNode);
            map.erase(key);
            delete oldNode;
        }

        // agar capacity full hai, LRU (dummyTail se pehला) node evict karo
        if(map.size() == capacity){
            Node* lru = dummyTail->prev;
            removeNode(lru);
            map.erase(lru->key);
            delete lru;
        }

        // naya node banao, front pe daalo, map mein rakho
        Node* newNode = new Node(key, value);
        insertAtFront(newNode);
        map[key] = newNode;
    }
};

int main(){
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1

    cache.put(3, 3); // evicts key 2
    cout << cache.get(2) << endl; // -1

    cache.put(4, 4); // evicts key 1
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}