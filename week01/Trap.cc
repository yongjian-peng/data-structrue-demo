#include "../stdc++.h"


class Trap {
    public:
        int main() {
            int heights[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
            vector<int> hei(heights, heights + 12);
            cout << trap2(hei) << endl;
            // 竖条解题 维护前缀 后缀 最大值
            // cout << trapheight(hei) << endl;
            return 0;
        }

    private:
        struct Rect {
            int width;
            int height;
        };
        // 单调栈
        stack<Rect> s;

        vector<int> preMax;
        vector<int> sufMax;

        int trap2(vector<int> &heights)
        {
            // 维护一个递减的这个底的形状 柱子的形状递减的这样的一个 单调栈
            // 水的面积应该是累加宽度乘上二者较小者（前一个、后一个 较小者）
            // 以一个固定的底 它两侧能扩展多远，来一个更高的块 挡住就扩展不了了
            // 需要我们把底这个栈顶的底的高度记录下来
            int ans = 0;
            for (int height : heights)
            {
                int accmulateWidth = 0;
                while (!s.empty() && s.top().height <= height)
                {
                    int bottom = s.top().height;
                    accmulateWidth += s.top().width;
                    s.pop();
                    // 以 bottom 为底的横块水 最高可以到 up （左右两侧高度的 min）
                    if (s.empty())
                        continue; // 水从左边流走了
                    int up = min(height, s.top().height);
                    // int up = height;
                    // if (!s.empty() && s.top().height < up) up = s.top().height;
                    ans += accmulateWidth * (up - bottom);
                }
                s.push({accmulateWidth + 1, height});
            }
            return ans;
        }

        int trapheight(vector<int> &heights)
        {
            //  以竖条累加 每个竖条最多能盛多少水呢 盛的是左右也就是前缀 后缀 （最大值）我们维护两个max（前缀 后缀的最大值）
            int n = heights.size();
            preMax = vector<int>(n);
            sufMax = vector<int>(n);
            preMax[0] = heights[0];
            for (int i = 1; i < n; i++)
            {
                preMax[i] = max(preMax[i - 1], heights[i]);
            }

            sufMax[n - 1] = heights[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                sufMax[i] = max(sufMax[i + 1], heights[i]);
            }

            int ans = 0;
            for (int i = 1; i < n - 1; i++)
            {
                int up = min(preMax[i - 1], sufMax[i + 1]);
                int bottom = heights[i];
                if (up > bottom)
                    ans += up - bottom;
            }
            return ans;
        }
};