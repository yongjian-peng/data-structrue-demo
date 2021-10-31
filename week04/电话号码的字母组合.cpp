/**
 * leetcode [17.] 电话号码的字母组合
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
   题解：使用深度优先搜索 
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
    
public:
    vector<string> letterCombinations(string digits) {
        this->disits = digits;
        alphabet['2'] = "abc";
        alphabet['3'] = "def";
        alphabet['4'] = "ghi";
        alphabet['5'] = "jkl";
        alphabet['6'] = "mno";
        alphabet['7'] = "pqrs";
        alphabet['8'] = "tuv";
        alphabet['9'] = "wxyz";

        if (digits.empty())
            return ans;
        dfs(0);
        return ans;
    }

private:
    void dfs(int index) {
        // 数字走完了
        if (index == digits.length()) {
            ans.push_back(str);
            return;
        }
        for (char ch : alphabet[digits[index]]) {
            str.push_back(ch);
            dfs(index + 1);
            str.pop_back(ch);
        }
    }
    string digits;
    string str;
    vector<string> ans;
    unprdered_map<char, string> alphabet;
};