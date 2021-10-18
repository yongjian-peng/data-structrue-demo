/*
 * leetcode [146.] LRU 缓存机制
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        LRUCache(int capacity) : capacity(capacity) {
            head.next = &tail;
            tail.pre = &head;
        }
        int get(int key)
        {
            // 查询是否存在
            if (h.find(key) == h.end())
            {
                return -1;
            }
            Node *item = h[key];
            deleteList(item);
            insertList(item);
            return item->value;
        }

        void put(int key, int value)
        {
            // 如果存在 先删除 然后再压入到 mp 中

            // 如果不存在则直接压入到 mp 中
            if (h.find(key) == h.end())
            {
                Node *item = new Node();
                item->key = key, item->value = value;
                insertList(item);
                h[key] = item;
            }
            else
            {
                Node *item = h[key];
                item->value = value;
                deleteList(item);
                insertList(item);
            }

            // 如果 当前的大小 大于规定的值 则删除链表末尾的值
            if (h.size() > capacity)
            {
                Node *node = tail.pre;
                deleteList(node);
                h.erase(node->key);
                delete node;
            }
        }

    private:
        struct Node
        {
            int key;
            int value;
            Node *pre;
            Node *next;
        };

        // 插入lianbiao
        // pre -> head -> tail
        // pre <- head <- tail
        void insertList(Node *node)
        {
            head.next->pre = node;
            node->next = head.next;
            head.next = node;
            node->pre = &head;
        }

        // 删除链表
        void deleteList(Node *node)
        {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        int capacity;
        // 需要 链表存cache hash 存 映射
        unordered_map<int, Node *> h;
        Node head, tail;
};