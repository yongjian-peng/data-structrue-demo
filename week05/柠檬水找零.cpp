
/**
 * leetcode [860.] 柠檬水找零
输入：bills = [5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 t

链接：https://leetcode-cn.com/problems/lemonade-change
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    bool lemonadeChange(vector<int>& bills) {
        coins[5] = coins[10] = coins[20] = 0;
        for (int bill : bills) {
            coins[bill]++;
            if (!exchange(bill - 5))
                return false;
        }
        return true;
    }

private:
    bool exchange(int amount) {
        for (int x : {20, 10, 5}) {
            while (amount >= x && coins[x] > 0) {
                amount -= x; // 金额减去 x
                coins[x]--; // 面值 x 找了零钱一张
            }
        }
        return amount == 0;
    }

    unordered_map<int, int> coins;
};