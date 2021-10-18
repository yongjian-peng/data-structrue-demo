/*
 * leetcode [560] 和为k的子数组
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int subarraySum(vector<int>& nums, int k) {
            // 使用前缀和 map 和记录 key 出现的频率记录为 值
            unordered_map<int, int> mp;
            mp[0] = 1;
            int count = 0, pre = 0;
            for (int i = 0; i < nums.size(); i++) {
                pre += nums[i]; // 记录当前的前缀和
                if (mp.find(pre - k) != mp.end()) { // pre - k 
                    count += mp[pre - k];
                }
                // 以和为key 出现的频率记录为 value
                mp[pre]++;
            }
            return count;
        }
};