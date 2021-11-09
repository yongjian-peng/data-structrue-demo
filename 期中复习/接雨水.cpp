

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
    // 题解 单调队列

public:
    int trap(vector<int>& heights) {
        // 维护一个递减的这个底的形状 柱子的形状递减的这样的一个单调栈
        // 水的面积应该是累加宽度乘上二者的较小者（前一个、后一个较小者）
        // 已一个固定的底 它两侧能扩展多远 来了一个更高的块 挡住就扩展不了
        // 需要我们的把底着栈顶的底高度记录下来
        int ans = 0;
        for (int height : heights) {
            int accmulateWidht = 0;
            while (!s.empty() && s.top().height <= height) {
                int bottom = s.top().height;
                accmulateWidht += s.top().width;
                s.pop();
                // 以 bottom 为底的横块水 最高可以到 up（左右两侧高度的 min）
                if (s.empty())
                    continue;
                int up = min(height, s.top().height);
                ans += accmulateWidht * (up - bottom);
            }
            s.push({accmulateWidht + 1, height});
        }
        return ans;
    }

private:
    struct Rect {
        int widht;
        int height;
    };
    // 单调栈
    stack<Rect> s;
};