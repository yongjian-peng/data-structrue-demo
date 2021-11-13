
/**
 * leetcode [63.] 不同路径2
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

链接：https://leetcode-cn.com/problems/unique-paths-ii
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0)
            return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> f(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    f[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    f[i][j] = 1;
                } else if (i == 0) {
                    f[i][j] = f[i][j - 1];
                } else if (j == 0) {
                    f[i][j] = f[i - 1][j];
                } else {
                    // i j 等于 左和上的路径之和 一直叠加的方式
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[n - 1][m - 1];
    }
};