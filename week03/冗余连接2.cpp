/*
 * leetcode [685.] 冗余连接 II
输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
输出：[4,1]

链接：https://leetcode-cn.com/problems/redundant-connection-ii/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解：并查集 或者使用 依次减少一条边，然后查找是否是一颗完整的树

public:
    vector<int> findRedundantDirectedConnection(Vector<vector<int>>& edges) {
        int inDegeree[N] = {0};// 记录节点的度
        n = edges.size(); // 边的数量
        for (int i = 0; i < n; i++) {
            inDegeree[edges[i][1]]++; // 统计入度
        }
        vector<int> vec; // 记录边的入度为2 （如果有的话，那么边数等于2）
        // 找到入度为2的节点所对应的边，主要要倒序，因为优先返回最后出现在二维数组中的答案
        for (int i = n - 1; i >= 0; i--) {
            if (inDegeree[edges[i][1]] == 2) {
                vec.push_back(i); // 压入edges 的 下标
            }
        }
        // 如果有入度为2 的节点，那么一定是两条边里删除一个，看删除哪个可以构成树
        if (vec.size > 0) {
            if (isTreeAfterRemoteEdge(vec[0])) {
                return edges[vec[0]];
            } else {
                return edges[vec[1]];
            }
        }

        // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边，返回就可以了
        return getRemoteEdge(edges);
    }

private:
    static const int N = 1010;
    int father[N];
    int n; // 边的数量
    // 并查集初始化
    void init() {
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程，谁是大哥
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将 v->u 这条边加入并查集 合并帮派
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        father[v] = u; // 把 u 合并到 v 中
    }
    // 对比 u 和 v 是否是同一个大哥
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    // 在有向图里找到删除的那条边，使其变成树
    vector<int> getRemoteEdge(const vector<vector<int>>& edges) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (same(edges[i][0], edges[i][1])) {
                return edges[i];
            }
            join(edges[i][0], edges[i][1]); // 加入帮派中
        }
        return {};
    }
    // 删除一条边之后 判断是不是树
    bool isTreeAfterRemoteEdge(const vector<vector<int>>& edges, int deleteEdge) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (i == deleteEdge)
                continue;
            if (same(edges[i][0], edges[i][1])) {
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }
};