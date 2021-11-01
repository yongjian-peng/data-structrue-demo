
/**
 * leetcode [450.] 删除二叉搜索树中的节点
输入：root = [5,3,6,2,4,null,7], key = 3
输出：[5,4,6,2,null,null,7]
解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。

链接：https://leetcode-cn.com/problems/delete-node-in-a-bst
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode() {}
     *     TreeNode(int val) { this.val = val; }
     *     TreeNode(int val, TreeNode left, TreeNode right) {
     *         this.val = val;
     *         this.left = left;
     *         this.right = right;
     *     }
     * }
     */
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        // 如果 删除的节点 和 root 相等
        if (root->val == key) {
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            TreeNode* next = root->right;
            // 右子树 一路向左 
            while (next->left != nullptr)
                next = next->left;
            root->right = deleteNode(root->right, next->val);
            root->val = next->val;
            return root;
        }
        // 如果小于 root 则 删除的节点在 root 的 左子树
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            // 如果大于root 则 删除的节点在 root 的右子树
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};