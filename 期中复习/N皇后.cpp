
/*
 * leetcode [51.] N 皇后
示例 1：
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

链接：https://leetcode-cn.com/problems/n-queens
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解 使用 dfs 深度优先搜索 + 左对角线 + 右对角线 都没有使用过

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        used = vector<bool>(n, false);
        dfs(0);
        vector<vector<string>> result;
        for (vector<int>& p : ans) {
            vector<string> pattern(n, string(n, '.'));
            for (int row = 0; row < n; row++) {
                pattern[row][p[row]] = 'Q';
            }
            result.push_back(pattern);
        }
        return result;
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