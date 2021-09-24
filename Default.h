#ifndef DEFAULT_H
#define DEFAULT_H
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : 
        val(x), next(NULL) {
    
    }
};

void ShowList(ListNode *h)
{
    while (h != NULL)
    {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
}

struct Node
{
    struct Node *left, *right;
    int key;
};

Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};

struct NodeL
{
    int val;
    int idx;
    NodeL *pre;
    NodeL *next;
};

    // void swap(int x, int y)
    // {
    //     int temp = y;
    //     y = x;
    //     x = temp;
    //     cout << x << ":" << y << endl;
    // }

    // void pswap(int *x, int *y)
    // {
    //     int temp = *y;
    //     *y = *x;
    //     *x = temp;
    // }

struct tmp1 // 运算符重载
{
    int x;
    tmp1(int a) { x = a; }
    bool operator<(const tmp1& a) const
    {
        return x < a.x; // 大顶堆
    }
};

// 方法二
struct tmp2 // 重写仿函数
{
    bool operator() (tmp1 a, tmp1 b)
    {
        return a.x < b.x; // 大顶堆
    }
};

#endif