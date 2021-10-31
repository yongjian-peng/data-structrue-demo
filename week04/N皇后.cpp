
/**
 * leetcode [51.] N 皇后
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
   
   题解：使用深度优先搜索

   提示：

1 <= n <= 9
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        used = vector<bool>(n, false);
        dfs(0);
    }

private:
    void dfs(int row) {
        if (row == n) {
            ans.push_back(p);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!used[col] && !usedPlus[row + col] && !usedMinus[row - col]) {
                p.push_back(col);
                used[col] = true;
                usedPlus[row + col] = true;
                usedMinus[row - col] = true;
                dfs(row + 1);
                used[col] = false;
                usedPlus[row + col] = false;
                usedMinus[row - col] = false;
                p.pop_back();
            }
        }
    }
    int n;
    vector<int> p;
    vector<bool> used;
    unordered_map<int, bool> usedPlus;
    unordered_map<int, bool> usedMinus;
    vector<vector<int>> ans;
};