
/**
 * leetcode [1143.] 最长公共子序列
输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace" ，它的长度为 3 。

链接：https://leetcode-cn.com/problems/longest-common-subsequence/
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
    // 当前的 i 和 j 是否相等 如果相等 加 1 如果不相等 则 取之前相等的最大值
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        text1 = " " + text1;
        text2 = " " + text2;

        // 存储 i j 对应的相同字符的数量 
        vector<vector<int>> f(m + 1， vector<int>(n + 1));
        vector<vector<int>> preType(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                // f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (text1[i] == text2[j]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    preType[i][j] = 2;
                } else {
                    if (f[i - 1][j] > f[i][j - 1]) {
                        f[i][j] = f[i - 1][j];
                        preType[i][j] = 0;
                    } else {
                        f[i][j] = f[i][j - 1];
                        preType[i][j] = 1;
                    }
                }
            }

        print_r(text1, text2, preType, m, n);
        return f[m][n];
    }

private:
    // 打印输出
    void print_r(string text1, string text2, vector<vector<int>>& preType, int i, int j) {
        if (i == 0 || j == 0)
            return;
        if (preType[i][j] == 0)
            print_r(text1, text2, preType, i - 1, j);
        else if (preType[i][j] == 1)
            print_r(text1, text2, preType, i, j - 1);
        else {
            print_r(text1, text2, preType, i - 1, j - 1);
            cout << text1[i] << endl;
        }
    }
};