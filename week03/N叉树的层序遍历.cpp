
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

        q.push(root);
        while(!q.empty()) {
            // 逐层去压入到数组 seq 中
            vector<int> currlevel; // 初始化当前层的数组
            for (int i = 0; i < q.size(); i++) {
                Node* node = q.front();
                q.pop();
                currlevel.push_back(node->val);
                for (auto n : node->children) { // 下一层去压入新的数组元素
                    q.push(n);
                }
            }
            seq.push_back(currlevel); 
        }
        return seq;
    }

private:
    queue<Node *> q;
    vector<vector<int>> seq;
};