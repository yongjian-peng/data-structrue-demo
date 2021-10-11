#include "stdc++.h"

using namespace std;

class GroupAnagrams {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            for (string& s : strs) {
                string copy = s;
                sort(copy.begin(), copy.end());
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
        vector<vector<string>> groups;
};