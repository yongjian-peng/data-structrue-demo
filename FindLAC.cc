
/* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream>
 
using namespace std;

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