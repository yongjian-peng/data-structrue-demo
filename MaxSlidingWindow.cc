#include "stdc++.h"

using namespace std;
class MaxSlidingWindow {
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 删除那些永远不能成为最优解的那些数
        // 下标时间 递增 值递减的队列
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // 删除出界的选项
            while (!q.empty() && q.front() <= i - k)
                q.pop_front();
            // 插入新选项 i 维护单调性
            while (!q.empty() && nums[q.front()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }

private:
    deque<int> q; // 存储下标
};