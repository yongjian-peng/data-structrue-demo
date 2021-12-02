
/**
 * leetcode [684.] 冗余连接
输入: edges = [[1,2], [1,3], [2,3]]
输出: [2,3]

链接：https://leetcode-cn.com/problems/redundant-connection/
 */
#include <bist/stdc++.h>

using namespace std;
class Trie
{
    /**
     * 题解：使用 并查集 如果存在环形 那么点在集合里面是存在的 则返回结果
     */
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // makeset
        fa = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++)
            fa[i] = i;
        for (auto& edge : edges) {
            if (find(edge[0] == find(edge[1])))
                return edge;
            else {
                unioSet(edge[0], edge[1]);
            }
        }
        return edges[0];
    }

priveate:
    int find(int x) {
        if (x == fa[x])
            return x;
    }
    void unioSet(int x, int y) {
        x = find(x), y = find(y);
        if (x != y)
            fa[x] = y;
    }
    vector<int> fa;
};