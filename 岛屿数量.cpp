/**
 * leetcode [200.] 岛屿数量 标记过的 是否有访问过 BFS 广度优先搜索 使用队列
示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{

public:
    int numIsLands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    BFS(grid, i, j);
                }
            }
        }
    }

private:
    void BFS(vector<vector<char>>& grid, int sx, int sy) {
        queue<pair<int, int>> q; // 是否能够继续往下走
        // 方向数组
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};

        q.push({sx, sy});
        visited[sx][sy] = true;
        while (!q.empty()) {
            // 第一步：取对头
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // 第二步：扩展对头
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                // 是否越界
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                // 是否有标记过
                if (grid[nx][ny] != '1')
                    continue;
                if (visited[nx][ny])
                    continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    int m, n;
    vector<vector<bool>> visited; // 是否有标记过
};