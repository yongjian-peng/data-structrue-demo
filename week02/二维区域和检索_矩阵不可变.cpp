/*
 * leetcode [304.] 二维区域和检索 - 矩阵不可变
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        NumMatrix(vector<vector<int>>& matrix) {
            // s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + s[i][j]
            vector<vector<int>> 
        }

        int sumRegion(int row1, int col1, int row2, int col2) {
            // sum(p,q,i,j) = s[i][j] - s[i][q-1] - s[p-1][j] + s[p-1][q-1];
        }
};