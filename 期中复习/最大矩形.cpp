
/*
 * leetcode [85.] 最大矩形
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6

链接：https://leetcode-cn.com/problems/maximal-rectangle/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解 矩形转换为 柱状图 然后计算柱状图中的最大数字

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }

        int n = matrix[0].size();
        int ret = 0;
        vector<int> left(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] += 1;
                } else {
                    left[j] = 0;
                }
            }
            ret = max(ret, largestRectangleArea(left));
        }
        return ret;
    }

private:

    int largestRectangleArea(vector<int>& heights) {
        // 单调栈 如果破坏了递增的性质 则 宽度增加 计算面积
        stack<Rect> s;
        heights.push_back(0);
        int ans = 0;
        for (int height : heights) {
            int accumulatedWidht = 0;
            while (!s.empty() && s.top().height >= height) {
                accumulatedWidht += s.top().widht;
                ans = max(ans, s.top().height * accumulatedWidht);
                s.pop();
            }
            s.push({accumulatedWidht + 1, height});
        }
        return ans;
    }
    // 小矩形
    struct Rect {
        int widht;
        int height;
    };
};