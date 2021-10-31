/**
 * leetcode [701.] 二叉搜索树中的插入操作
 * 输入：root = [4,2,7,1,3], val = 5
   输出：[4,2,7,1,3,5]
   链接：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
 */
#include <bist/stdc++.h>

using namespace std;

class Solution {
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};