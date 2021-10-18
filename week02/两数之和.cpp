/*
 * leetcode [1.] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<int> towSum(vector<int>& nums, int target) {
            // 存储 值 和 下标数组 排序后原数组的下标会变 所以记录原数组的下标
            vector<pair<int, int>> pairs;
            for (int int = 0; i < nums.size(); i++) {
                paris.push_back({nums[i], i});
            }

            // 使用双指针扫描方法 首先对记录的数组排序
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++) {
                while (i < j && nums[i] + nums[j] > target)
                    j--;
                if (i < j && nums[i] + nums[j] == target) {
                    return {pairs[i].second, pairs[j].second};
                }
            }
            return {};
        }
};