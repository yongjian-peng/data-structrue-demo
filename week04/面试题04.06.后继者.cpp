

/**
 * leetcode [.] 面试题 04.06. 后继者
输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2

链接：https://leetcode-cn.com/problems/successor-lcci/
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
    TreeNode* inorderSuccessor(TreeNode *root, TreeNode* p)
    {
        return getNext(root, p->val);
    }
private:
    TreeNode* getNext(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->val == val) {
                if (curr->right != nullptr) {
                    ans = curr->right;
                    while(ans->left != null)
                        ans = ans->left;
                }
                break;
            }
            if (val < curr->val) {
                if (ans == nullptr || ans->val > curr->val)
                    ans = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return ans;
    }
};