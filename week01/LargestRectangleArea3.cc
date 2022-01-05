#include "../stdc++.h"


class LargestRectangleArea3 {
    public:
        int main() {
            LargestRectangleArea3 Lra3;
            int heights2[] = {2, 1, 5, 6, 2, 3};
            vector<int> hei2(heights2, heights2 + 6);
            cout << Lra3.largestRectangleArea3(hei2) << endl;
            return 0;
        }
        int largestRectangleArea3(vector<int>& heights) {
            // 最大矩形 使用单调栈 
            // 维护递增 或者递减 的顺序 递增 如果破坏了 递增或者递减的顺序 则弹出栈宽度累加
            // 计算最大矩形 然后存入
            int ans = 0;

            heights.push_back(0);
            
            for (int height : heights)
            {
                // 累加款度
                int accumulatedWidth = 0;
                while (!s.empty() && s.top().height >= height) {
                    accumulatedWidth += s.top().width;
                    ans = max(ans, accumulatedWidth * s.top().height);
                    s.pop();
                }

                s.push({accumulatedWidth + 1, height});
            }
            return ans;
        }

    private:
        struct Rect
        {
            int width;
            int height;
        };
        stack<Rect> s;
};