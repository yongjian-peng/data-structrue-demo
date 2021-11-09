

/*
 * leetcode [239.] 滑动窗口最大值
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]

链接：https://leetcode-cn.com/problems/sliding-window-maximum/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解 单调队列

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 删除那些永远不能成为最优解的那些数
        // 下标时间 递增 值 递减的队列
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // 删除出界的选项
            while (!q.empty() && q.front() <= i - k)
                q.pop_front();
            // 维护单调性 插入新选型 i
            while (!q.empty() && nums[q.back()] < nums[i])
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