
/*
 * leetcode [589.] N 叉树的前序遍历
 示例 1：
输入：root = [1,null,3,2,4,null,5,6]
输出：[1,3,5,6,2,4]
 */

#include <bits/stdc++.h>
    using namespace std;

class Solution
{
    /*
    // Definition for a Node.
    class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };
    */
public:
    vector<int> preorder(Node *root)
    {
        dfs(root);
        return seq;
    }

private:
    void dfs(Node* root) {
        if (root == nullptr)
            return;
        seq.push_back(root->val);
        for (Node* child : root->children) {
            dfs(child);
        }
    }

    vector<int> seq;
};