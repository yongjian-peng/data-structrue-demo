/*
 * leetcode [1248.] 统计「优美子数组」
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int numberOfSubarrays(vector<int>& nums, int k) {
            // 原问题：子段和的奇数数量
            // 新问题：奇数看作1 偶数看作0 （每个数 mod 2）统计子段和 k 的子段数量
            // sum(l, r) == k
            // s[r] - s[l -1] == k (l <= r)
            // 两数之差 一个是 s[r]  一个是 s[l -1]
            int n = nums.size();
            vector<int> s(n + 1); // s[0~n]
            s[0] = 0;
            for (int i = 1; i <= n; i++) {
                s[i] = s[i - 1] + nums[i - 1] % 2;
            }
            int ans = 0;
            count[s[0]]++;
            for (int i = 1; i <= n; i++) {
                if (s[i] - k >= 0)
                    ans += count[s[i] - k];
                count[s[i]]++;
            }
            return ans;
        }
};