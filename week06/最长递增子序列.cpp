
/**
 * leetcode [300.] 最长递增子序列
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        vector<int> pre(n);
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            pre[i] = -1;
        }

        for (int i = 1; i < n; i++) { // 当前下标
            for (int j = 0; j < i; j++) { // 前一个下标
                if (nums[j] < nums[i] && f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    pre[i] = j;
                }
            }
        }
        int ans = 0;
        int end = -1;
        for (int i = 0; i < n; i++) {
            if (f[i] > ans) {
                ans = f[i];
                end = i;
            }
        }
        print_r(nums, pre, end);
        return ans;
    }

private:
    // 打印输出
    void print_r(vector<int>& nums, vector<int>& pre, int i) {
        if (pre[i] != -1)
            print_r(nums, pre, pre[i]);
        cout << nums[i] << endl;
    }
};