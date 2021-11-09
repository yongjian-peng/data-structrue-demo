
/*
 * leetcode [17.] 电话号码的字母组合
示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解 

public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        alphabet['2'] = "abc";
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
        if (index == digits.length()) {
            ans.push_back(str);
            return;
        }
        for (char ch : alphabet[digits[index]]) {
            str.push_back(ch);
            dfs(index + 1);
            str.pop_back();
        }
    }
    string digits;
    string str;
    vector<string> ans;
    unordered_map<char, string> alphabet; // 号码对应数字
};