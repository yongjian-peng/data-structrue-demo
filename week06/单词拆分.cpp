
/**
 * leetcode [139.] 单词拆分
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

链接：https://leetcode-cn.com/problems/word-break

 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < s.size(); i++) {
            if (!dp[i])
                continue;
            for (auto& word : wordDict) {
                if (word.size() + i <= s.size() && s.substr(i, word.size()) == word) {
                    dp[i + word.size()] = true;
                }
            }
        }
        return dp[s.size()];
    }
};