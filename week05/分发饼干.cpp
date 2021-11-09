
/**
 * leetcode [455.] 分发饼干
输入: g = [1,2,3], s = [1,1]
输出: 1
解释:
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1

链接：https://leetcode-cn.com/problems/assign-cookies
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        for (int child : g) {
            // s 饼干  g 孩子胃口 孩子胃口和饼干是否满足
            while (j < s.size() && s[j] < child)
                j++;
            if (j < s.size()) {
                ans++;
                j++;
            }
        }
        return ans;
    }
};