
/**
 * leetcode [538.] 把二叉搜索树转换为累加树
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
   题解：二叉搜索树 中序遍历满足 升序排序 遍历右子树 根 左子树 即倒序遍历 
 */
#include <bist/stdc++.h>

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
    int sum_num = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (root != nullptr) {
            convertBST(root->right);
            sum_num += root->val;
            root->val = sum_num;
            convertBST(root->left);
        }
        return root;
    }
};