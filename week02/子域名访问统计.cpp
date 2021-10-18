/*
 * leetcode [811] 子域名访问计数
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<string> subdomainVisits(vector<string>& cpdomains) {
            unordered_map<string, int> cnt;
            for (auto& word : cpdomains) {
                int idx = word.find(' ');
                // 字符串切割 求开头数量
                int num = stoi(word.substr(0, idx));
                string dmName = word.substr(idx + 1);
                while(idx > 0) {
                    cnt[dmName] += num;
                    idx = dmName.find('.');
                    // 依次向右以 . 为单位移动
                    dmName = dmName.substr(idx + 1);
                }
            }
            vector<string> ans;
            for (auto& c : cnt) {
                ans.push_back(to_string(c.second) + " " + c.first);
            }
            return ans;
        }
};