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