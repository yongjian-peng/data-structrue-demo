
/**
 * leetcode [322.] 零钱兑换
输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1

链接：https://leetcode-cn.com/problems/coin-change/
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount) {
        int inf = INX_MAX - 1;
        vector<int> opt = vector<int>(amount + 1);
        opt[0] = 0;
        // 寻找代表 兑换 0 的 需要零枚
        for (int i = 1; i <= amount; i++) {
            opt[i] = inf;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    opt[i] = min(opt[i], opt[i - coins[j]] + 1);
                }
            }
        }
        if (opt[amount] >= inf)
            opt[amount] = -1;
        return opt[amount];
    }
};