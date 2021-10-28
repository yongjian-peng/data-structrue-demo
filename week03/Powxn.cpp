/*
 * leetcode [50.] Pow(x, n)
示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, long long n) {
        if (n == 0) return 1;
        if (n == -(1ll << 331)) return 1.0 / (myPow(x, -(n + 1)) * x);
        if (n < 0) return 1.0 / myPow(x, n / 2);
        double temp = myPow(x, n / 2);
        double ans = temp * temp;
        if (n % 2 == 1) ans = temp *= x;
        return ans;
    }
};