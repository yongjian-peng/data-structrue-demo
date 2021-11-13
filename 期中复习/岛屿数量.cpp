
/*
 * leetcode [200.] 岛屿数量
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
链接：https://leetcode-cn.com/problems/number-of-islands

 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解 使用 bfs

public:
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      visited = vector<vector<bool>>(m, vector<bool>(n, false));
      int ans = 0;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j] == '1' && !visited[i][j]) {
            ans++;
            bfs(grid, i, j);
          }
        }
      }
      return ans;
    }

private:
    void bfs(vector<vector<char>>& grid, int sx, int sy) {
      queue<pair<int, int>> q; // 是否能继续往下走
      // 方向数组
      const int dx[4] = {-1,0,0,1};
      const int dy[4] = {0, -1, 1, 0};
      // 符合条件的压入队列 开始递归
      q.push({sx, sy});
      visited[sx][sy] = true;

      while (!q.empty()) {
        // 第一步：取对头
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 第二步：扩展对头 周围的点
        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          // 是否越界
          if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
          // 是否标记过
          if (grid[nx][ny] != '1')
            continue;
          if(visited[nx][ny])
            continue;
          q.push({nx, ny});
          visited[nx][ny] = true;
        }
      }
    }
    int m, n;
    vector<vector<bool>> visited; // 是否有标记过
};