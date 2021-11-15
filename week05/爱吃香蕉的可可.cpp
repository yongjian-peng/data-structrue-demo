
/**
 * leetcode [875.] 爱吃香蕉的可可
输入: piles = [3,6,7,11], H = 8
输出: 4

链接：https://leetcode-cn.com/problems/koko-eating-bananas/

 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    // 题解 使用二分查找 
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0;
        for (int pile : piles) {
            mx = max(mx, pile);
        }
        int left = 1, right = mx;
        while (left < right) {
            int mid = (left + right) >> 1;
            int (!validate(piles, mid, h)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

private:
    int validate(vector<int>& piles, int mid, int h) {
        int cnt = 0; // 初始化所用小时
        if (mid == 0)
            return INT_MAX;
        for (int pile : piles) {
            if (pile % mid != 0) {
                cut++;
            }
            cnt += (pile / mid);
        }
        return cut <= h;
    }
};