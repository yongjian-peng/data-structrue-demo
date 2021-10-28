
/*
 * leetcode [329.] 矩阵中最长递增路径
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
    // 题解：使用 深度优先搜索 方向数组 + 矩阵转一维数组 + 记忆化搜索 = 从下到上位置出发搜索
    // 广度优先搜索 方向数组 + 矩阵转一维数组 + 拓扑排序 = 从0起点位置 从上到下位置出发

public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        // 初始化
        this->matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();

        dist = vector<vector<int>>(m, vector<int>(n, 0));
        // 建方向数组
        dx = {-1,0,0,1};
        dy = {0,-1,1,0};
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(i, j));

        return ans;
    }

private:
    int dfs (int x, int y) {
        if (dist[x][y] != 0)
            return dist[x][y];
        dist[x][y] = 1;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (valid(nx, ny) && matrix[nx][ny] > matrix[x][y]) {
                // 从 xy 出发 往下走就是 xy 起点 到 底可以走多长 回溯一层多一层加一
                dist[x][y] = max(dist[x][y], dfs(nx, ny) + 1);
            }
        }
        return dist[x][y];
    }
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    // 矩阵转一维数组
    int num(int i, int j) {
        return i * n + j;
    }
    int m, n;
    vector<vector<int>> matrix;
    vector<vector<int>> dist; // 记忆化存储 包含点记录
    vector<int> dx;
    vector<int> dy;
};