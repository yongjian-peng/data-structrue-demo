/*
 * leetcode [49.] 字母异位词分组
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            // 对字符串排序
            for (string& s : strs) {
                string copy = s;
                sort(s.begin(), s.end());
                if (groups.find(copy) == groups.end()) {
                    groups[copy] = {};
                }
                groups[copy].push_back(s);
            }
            vector<vector<string>> ans;
            for (const pair<string, vector<string>>& group : groups) {
                ans.push_back(group.second);
            }
            return ans;
        }

    private:
        unordered_map<string, vector<string>> groups;
};