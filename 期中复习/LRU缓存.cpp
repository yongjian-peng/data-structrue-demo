/*
 * leetcode [146.] LRU 缓存机制
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4

链接：https://leetcode-cn.com/problems/lru-cache


 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 缓存 LRU

public:
    LRUCache(int capacity) : capacity(capacity) {
        head.next = &tail;
        tail.pre = &head;
    }

    int get(int key) {
        if (h.find(key) == h.end())
            return -1;
        Node *item = h[key];
        removeFromList(item);
        insertToList(item);
        return item->value;
    }

    void put(int key, int value) {
        if (h.find(key) == h.end()) {
            Node *item = new Node();
            item->key = key;
            item->value = value;
            insertToList(item);
        } else {
            Node *item = h[key];
            removeFromList(item);
            insertToList(item);
        }

        if (h.size() > capacity) {
            Node *node = tail.pre;
            removeFromList(node);
            h.erase(node->key);
            delete node;
        }
    }

private:
    void removeFromList(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void insertToList(Node* node) {
        head.next->pre = node;
        node->next = head.next;

        head.next = node;
        node->pre = &head;
    }
    struct Node {
        int key;
        int value;
        Node* pre;
        Node* next;
    };

    int capacity;
    unordered_map<int, Node *> h;
    Node head, tail;
};