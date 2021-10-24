
/*
 * leetcode [429.] N 叉树的层序遍历
输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]
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
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
            return seq;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int depth = q.front().second;
            q.pop();

            if (depth >= seq.size())
                seq.push_back(vector<int>());
            seq[depth].push_back(node->val);

            for (Node *child : node->children)
            {
                q.push({child, depth + 1});
            }
        }
        return seq;
    }

private:
    queue<pair<Node *, int>> q;
    vector<vector<int>> seq;
};