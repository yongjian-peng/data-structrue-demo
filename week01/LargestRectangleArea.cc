#include "../stdc++.h"

using namespace std;

class LargestRectangleArea {
    public:
        int largestReactangleArea(vector<int>& heights) {
            // 最大矩形 宽度 高度
            // 高度 每个高度可以扩展的范围 更新高度 删除高度 增加宽度
            // 高度删除 宽度接着使用的思路
            // 删柱子 新增柱子都是在末尾 一个容器需要存储一些柱子 它只在尾部插入删除 单调性维护增长 加一个需要在尾部操作的容器
            // 刚开始栈为空的 依次扫描每一个宽度为 1 的柱子 一共 n 个柱子
            // 尝试它们的高度来去向左右扩展 我们把扩展范围确定 所以要扫描每一根柱子
            // 对于每一种满足的情况有两种 一 满足 单调递增 我直接入栈即可
            // 二 单调性破环了 我需要把栈顶元素给它删除 对吧 栈顶这个元素 这个柱子 它向左向右扩展的宽度的位置范围已经确定了
            // -- 我就可以用栈顶的高度 乘以 宽度这个范围 把一个答案更新 然后把它删除 同时累加宽度
            // 全局答案
            int ans = 0;
            heights.push_back(0); // 保证栈被弹空 避免重写一次循环 while
            for (int height : heights) {
                // 累加宽度
                int accumulatedWidth = 0;
                // 栈顶（之前）高度 >= 当前高度 单调性破坏 确定了栈顶高度的扩展范围，需要删除栈顶
                while (!s.empty() && s.top().height >= height) {
                    accumulatedWidth += s.top().width;
                    ans = max(ans, s.top().height * accumulatedWidth);
                    s.pop();
                }
                s.push({accumulatedWidth + 1, height});
            }
            return ans;
        }

    private:
        // 小矩形
        struct Rect {
            int width;
            int height;
        };
        // 单调栈
        stack<Rect> s;
};