/*
 * leetcode [297.] 二叉树的序列化与反序列化
输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
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
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
public:
    string serialize(TreeNode* root) {
        string str;
        dfs(str, root);
        return str;
    }

    TreeNode* deserialize(string data) {
        s = "";
        // 1,2,3,null,null,4,5
        for (char c : data) {
            if (c == ',') {
                seq.push(s);
                s = "";
                continue;
            }
            s += c;
        }
        return makeTree(seq);
    }

private:
    void dfs(string str &, TreeNode *root)
    {
        if (root == nullptr)
        {
            str += "null,";
        }
        else
        {
            str += to_string(root->val) + ",";
            dfs(str, root->left);
            dfs(str, root->right);
        }
    }

    TreeNode *makeTree(queue<string> &seq)
    {
        string st = seq.front();
        seq.pop();
        if (st == "null")
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(st));
        root->left = makeTree(seq);
        root->right = makeTree(seq);
        return root;
    }
    queue<string> seq; // 使用队列代替了数组 数组访问的是某一个元素 队列访问的也是某一个元素
    string s;
};