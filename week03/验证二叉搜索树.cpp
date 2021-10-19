/*
 * leetcode [98.] 验证二叉搜索树
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
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
    bool isValidBST(TreeNode* root) {
        return check(root, -(1l << 31), (1ll << 31 - 1));
    }

private:
    bool check(TreeNode* root, long long rangeLeft, long long rangeRight) {
        if (root == nullptr)
            return true;
        if (root->val < rangeLeft || root->val > rangeRight)
            return false;
        return check(root->left, rangeLeft, root->val - 1l) &&
               check(root->right, root->val + 1, rangeRight);
    }
};