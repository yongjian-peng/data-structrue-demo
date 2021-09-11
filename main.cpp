#include <iostream>
#include "TwoSum.cc"
#include "CorpFlight.cc"
#include "Reverse.cc"
#include "FindLAC.cc"
#include "Heapify.cc"
#include "ReverseBetween.cc"
#include "PrintLink.cc"
#include "Default.h"
#include "KthLargest.cc"
#include "HeapSorti.cc"
#include "MergeArray.cc"
#include "PushZerosToEnd.cc"
using namespace std;

int main()
{
    // TwoSum two;
    // int arr[4] = {2, 2, 2, 7};
    // vector<int> ao(arr, arr + 4);
    // vector<int> aw;
    // aw = two.twoSum1(ao, 9);

    // //cout << aw << endl;

    // int num = aw.size();

    // cout << num << endl;

    // for (int i = 0; i < num; i++)
    // {
    //     cout << aw[i] << endl;
    // }

    // CorpFlight corp;

    // vector<vector<int>> array;

    // 链表
    // Reverse re;
    // ListNode* one = new ListNode(1);
    // ListNode* two_l = new ListNode(2);
    // ListNode* three = new ListNode(3);
    // ListNode* four = new ListNode(4);
    // ListNode* five = new ListNode(5);
    // ListNode* six = new ListNode(6);
    // one->next = two_l;
    // two_l->next = three;
    // three->next = four;
    // four->next = five;
    // five->next = six;
    // six->next = NULL;

    // cout << re.ReverseList(one)->val << endl;

    // 树 链表
    // Node * root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);

    // cout << "LCA(4,7) = " << findLCA_H(root, 4,7)->key;

    // int arr[] = { 12, 11, 13, 5, 6, 7 };

    // int n = sizeof(arr) / sizeof(arr[0]);

    // heapSort(arr, n);

    // cout << "Sorted array is \n";
    // printArray(arr, n);

    // 反转链表 输入 左 右 返回区间内反转
    // Solution st;

    // ReverseBetween reb;
    // ListNode* one = new ListNode(1);
    // ListNode* two = new ListNode(2);
    // ListNode* three = new ListNode(3);
    // ListNode* four = new ListNode(4);
    // ListNode* five = new ListNode(5);
    // ListNode *six = new ListNode(6);

    // one->next = two;
    // two->next = three;
    // three->next = four;
    // four->next = five;
    // five->next = NULL;

    // //vector<int> pr = st.printListFromTailToHead(one);
    // ListNode* ss = reb.reverseBetween(one, 2, 4);
    // ShowList(ss);

    // cout << reb.reverseBetween(one, 1, 4) << endl;

    // ------ 堆排序 ---------
    // int arr[] = {12, 11, 13, 5, 6, 7};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // heapSort(arr, n);

    // cout << "Sorted array is \n";
    // printArray(arr, n);

    // -------- 动态查找 第 k 大元素 ----------
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    // Node *root = NULL;
    // root = insert(root, 50);
    // insert(root, 30);
    // insert(root, 20);
    // insert(root, 40);
    // insert(root, 70);
    // insert(root, 60);
    // insert(root, 80);

    // int c = 0;
    // kthLargest(root, 6);
    // for (int k = 1; k <= 7; k++)
    // {
    //     kthLargest(root, k);
    // }

    // --------- 堆排序 ------------
    // int arr[] = {12, 11, 13, 5, 6, 7};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // HeapSorti heap;

    // heap.headSorti(arr, n);
    // heap.printArray(arr, n);

    // ---------- 合并两个有序数组 -------
    // int arr1[] = {1, 3, 5, 7};
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // int arr2[] = {2, 4, 6, 8};
    // int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // int arr3[n1 + n2];

    // mergeArrays(arr1, arr2, n1, n2, arr3);
    // int n3 = n1 + n2;
    // printArray(arr3, n3);

    // mergeArrays2(arr1, arr2, n1, n2);

    // ------- 移动零 ----------
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    pushZoresToEnd(arr, n);

    printArray(arr, n);
    return 0;
}