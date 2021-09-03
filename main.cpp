#include <iostream>
#include "TwoSum.cc"
#include "CorpFlight.cc"
#include "Reverse.cc"
#include "FindLAC.cc"
#include "Heapify.cc"
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

    // Node * root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);

    // cout << "LCA(4,7) = " << findLCA_H(root, 4,7)->key;

    int arr[] = { 12, 11, 13, 5, 6, 7 };

    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);

    return 0;
}