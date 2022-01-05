#include <iostream>
#include "../Default.h"

using namespace std;


int runKthLargest() {
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
    return 0;
}

void kthLargestUtil(Node *root, int k, int &c)
{
    // 判断当前节点是否为空 或者 k 是否大于或排名 c
    if (root == NULL || c >= k) {
        return;
    }
    cout << "aaa" << endl;
    // 调用右子节点 看是否是最大
    kthLargestUtil(root->right, k, c);
    // 排名 ++
    c++;
    // 判断是否是需要查找第 k 大元素
    if (c == k) {
        cout << "find is right :" << k << " s is " << root->key << endl;
        return;
    }
    // 调用左子节点 看是否存在
    kthLargestUtil(root->left, k, c);
}

void kthLargest(Node *root, int k) {
    // 调用 查找第 k 大元素
    int c = 0;
    kthLargestUtil(root, k, c);
}

// 插入一个树中 元素
Node* insert(Node* node, int key) {
     // 判断当前树是否为空，如果为空，初始化一棵树
    if (node == NULL) {
        return newNode(key);
    }
     // 如果要插入的值小于当前节点，则插入左节点 否则 反之
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    cout << "aabc" << endl;
    // 返回 node 树
    return node;
}