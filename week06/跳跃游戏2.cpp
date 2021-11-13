
/**
 * leetcode [45.] 跳跃游戏2
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

链接：https://leetcode-cn.com/problems/jump-game-ii
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    int jump(vector<int>& nums) {
        int now = 0;
        int ans = 0;
        while (now < nums.size() -1) {
            int right = now + nums[now];
            if (right >= nums.size() - 1)
                return ans + 1;
            int nextRight = right;
            int next = now;
            // 看下一步能够到达的最远距离
            for (int i = now + 1; i <= right; i++) {
                if (i + nums[i] > nextRight) {
                    nextRight = i + nums[i];
                    next = i;
                }
            }
            now = next;
            ans++;
        }
        return ans;
    }
};