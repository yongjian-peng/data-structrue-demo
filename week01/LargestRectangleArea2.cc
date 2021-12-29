#include "../stdc++.h"

class LargestRectangleArea2 {
    public:
    int largestRectangleArea2(vector<int>& heights) {
        // 计算柱状图中最大面积
        // 维护前缀 后缀 最大值 前缀的最大值 和 后缀的最大值差值 乘以宽度
        int n = heights.size();
        preMax = vector<int>(n);
        sufMax = vector<int>(n);
        // 赋值 preMax 【0】元素
        preMax[0] = heights[0];
        // 赋值 preMax 所有的元素
        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i- 1],heights[i]);
            cout << preMax[i] << " ";
        }
        cout << endl;
        // 赋值 sufMax 【0】元素
        sufMax[n - 1] = heights[n - 1];
        // 赋值 sufMax 所有元素
        for (int i = n - 2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i + 1], heights[i]);
            cout << sufMax[i] << " ";
        }
        cout << endl;
        // 循环计算 对比
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int up = min(preMax[i - 1], sufMax[i + 1]);
            cout << up << " ";
            int bottom = heights[i];
            if (up > bottom)
                ans += up - bottom;
        
        }
        // 返回结果
        return ans;
    }

private:
    vector<int> preMax;
    vector<int> sufMax;
};