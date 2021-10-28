/*
 * leetcode [329.] 矩形中最长增长路径-广度优先搜索
示例 3：

输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。

链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解：使用广度优先搜索 查找更改的基因 需要的深度，4个字母 基因有8个字符 改变包含 bank中
    // 每个改变的字母需要 查找 除了包含自己的 24 种基因排序

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       // 初始化
       m = matrix.size();
       n = matrix[0].size();
       to = vector<vector<int>>(m * n);
       deg = vector<int>(m * n, 0);
       dist = vector<int>(m * n, 0);
       // 建数组方向
       const int dx[4] = {-1,0,0,1};
       const int dy[4] = {0,-1,1,0};
       for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                // 从 0 点出发 往4个方向走 如果走到一个递增的点 就加边
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (valid(ni,nj) && matrix[ni][nj] > matrix[i][j])  {
                        // 建图
                        addEdge(num(i, j), num(ni, nj));
                    }
                }
        // 从 0 度点 为起点 去搜索 去 BFS 拓扑排序来考虑所有出边的扩展
        queue<int> q;
        for (int i = 0; i < m * n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                dist[i] = 1;
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : to[x]) {
                // 当一个点的入点都已扩展 已经求完了， max 最长了
                deg[y]--;
                dist[y] = max(dist[y], dist[x] + 1);
                // 入队 入扩展其他的 从多个 0 起点出发，去扩展别人那么到了一个点，其实就是 从某一 一为起点走到它最长的一个长度
                if (dist[y] == 0) q.push(y);
            }
        }
        int ans = 0;
        for (int i = 0; i < m * n; i++) {
            ans = max(ans, dist[i]);
        }
        return ans;
    }

private:
    int m, n;
    vector<vector<int>> to;
    vector<int> deg; // 入度
    vector<int> dist; // 从这些零入点之一为起点，找它最长的一点长度

    void addEdge(int u, int v) {
        deg[v]++;
        to[u].push_back(v);
    }
    int num(int i, int j) {
        return i * n + j;
    }
    bool valid(int i, int j) {
        return i >= 0; i < m && j >= 0 && j < n;
    }

};