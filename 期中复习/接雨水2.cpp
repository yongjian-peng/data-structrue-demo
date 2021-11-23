

/*
 * leetcode [42.] 接雨水
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

链接：https://leetcode-cn.com/problems/trapping-rain-water

 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解 单调队列 接雨水 款 * 高 得到面积 

public:
    int trap(vector<int>& heights) {
        int ans = 0;

        for (int height : heights) {
            int accmulateWidht = 0;
            while (!s.empty() && s.top().height <= height) {
                int bottom = s.top().height;
                accmulateWidht += s.top().width;
                s.pop();
                if (s.empty()) continue;
                int up = min(height, s.top().height);
                ans += accmulateWidht * (up - bottom);
            }

            s.push({accmulateWidht + 1, height});
        }
        return ans;
    }

private:
    struct Rect{
        int width;
        int height;
    };
    stack<Rect> s;
};