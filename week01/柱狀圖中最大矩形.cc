#include "<bits/stdc++.h>"

using namespace std;

class LargestRectangleArea {
    public:
        int largestRectangleArea(vector<int>& heights) {
            s.push({1, heights[0]});

            int ans = MIN_INT;
            for (int height : heights) {
                while (!s.empty()) {
                    // 1. 取对头
                    Rect q = s.top();
                    // 2. 检查是否破坏单调性
                    while (q.height < height) {
                        int widthdow = q.width;
                        int ans = max(ans, height * q.width);
                        s.pop();
                    }
                    // 3. 压入单调栈
                    s.push({widthdow + 1, height})
                }
            }
            return ans;
        }

    private:
        // 单调栈
        struct Rect {
            int width;
            int height;
        };
    stack<Rect> s;
};