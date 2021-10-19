/*
 * leetcode [46.] 全排列
 示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        n = nums.size();
        used = vector<bool>(n, false);
        recur(nums, 0);
        return ans;
    }

private:
    void recur(vector<int>& nums, int pos)
    {
        if (pos == n) {
            ans.push_back(chosen);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                chosen.push_back(nums[i]);
                used[i] = true;
                recur(nums, pos + 1);
                used[i] = false; // 还原现场
                chosen.pop_back();
            }
        }
    }

    vector<bool> used; // 选没有选过
    vector<int> chosen;
    int n;
    vector<vector<int>> ans;
};