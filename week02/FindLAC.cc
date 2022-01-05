
/* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream>
#include "../Default.h"
 
using namespace std;

int runfindmain() {
    // --------------- 树 链表 ---------------
    // Node * root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);

    // cout << "LCA(4,7) = " << findLCA_H(root, 4,7)->key;
    return 0;
}

struct Node *findLCA_H(struct Node* root, int n1, int n2)
{
    if (root == NULL) return NULL;

    if(root->key == n1 || root->key == n2)
        return root;
    
    Node *left_lca = findLCA_H(root->left, n1, n2);
    Node *right_lca = findLCA_H(root->right, n1, n2);

    if(left_lca && right_lca) return root;

    return (left_lca != NULL) ? left_lca : right_lca;
};