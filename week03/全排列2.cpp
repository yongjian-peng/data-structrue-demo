/*
 * leetcode [47.] 全排列2
 示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    递归解法 使用过的数 选或不选 则先排序数组 如果有重复的值 则continue
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // 排序去重的基础
        sort(nums.begin(), nums.end());
        n = nums.size();
    }

private:
    void recur(vector<int>& nums, int pos) {
        if (n == pos) {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            a.push_back(nums[i]);
            used[i] = true;
            recur(nums, pos + 1);
            used[i] = false;
            a.pop_back();
        }
    }
    vector<bool> used; // 选没有选过
    vector<int> a; // 结果数组中的单个元素
    int n; // n 的个数
    vector<vector<int>> ans;
};
