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

void ShowList(struct ListNode *h)
{
    while (h != NULL)
    {
        cout << h->val << endl;
        h = h->next;
    }
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

#endif