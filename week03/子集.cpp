/*
 * leetcode [78.] 子集
 示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

示例 2：

输入：nums = [0]
输出：[[],[0]]
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        recur(nums, 0);
        return ans;
    }

private:
    void recur(vector<int>& nums, int i) {
        if (i == n) {
            ans.push_back(chosen);
            return;
        }
        // 每层的相似逻辑 nums[i] 选或不选
        recur(nums, i + 1);
        chosen.push_back(nums[i]);
        recur(nums, i + 1);
        chosen.pop_back(); // 还原现场 有 n 个房间 你站在其中一个里 手里拿着篮子 
                           // 第一次你直接进了下一个房间，第二次你先在篮子里放了一个数，然后进入了下一个房间
    }

    int n;
    vector<int> chosen;
    vector<vector<int>> ans;
};