/*
 * leetcode [697] 数组的度
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int findShortestSubArray(vector<int>& nums) {
            // 记录数组的度 频率
            unordered_map<int, int> m;
            // 记录数组的元素开始的位置
            unordered_map<int, int> m1;
            // 数组的度初始化
            int degree = 0;
            int ans = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (m1.find(nums[i]) == m1.end()) {
                    m1[nums[i]] = i;
                }
                m[nums[i]]++;
                if (m[nums[i]] > degree) {
                    degree = m[nums[i]];
                    ans = i - m1[nums[i]] + 1;
                } else if (m[nums[i]] == degree) {
                    ans = min(ans, i - m1[nums[i]] + 1);
                }
            }

            return ans;
        }
};