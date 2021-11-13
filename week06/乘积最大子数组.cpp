
/**
 * leetcode [152.] 乘积最大子数组
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

链接：https://leetcode-cn.com/problems/maximum-product-subarray/
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> fmax(n);
        vector<int> fmin(n);
        fmax[0] = 0;
        fmin[0] = 0;

        for (int i = 1; i < n; i++) {
            fmax[i] = max(max(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]), nums[i]);
            fmin[i] = min(min(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]), nums[i]);
        }
        int ans = fmax[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, fmax[i]);
        }
        return ans;
    }
};