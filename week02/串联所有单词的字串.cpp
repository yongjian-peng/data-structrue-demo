/*
 * leetcode [30.] 串联所有单词的子串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            int top = 0;
            // 得出串联单词的总长度
            for (string& word : words) {
                top += word.length();
                // ["foo", "bar", "bar"] => {"foo": 1, "bar": 2}
                wordsMap[word]++;
            }

            // 用无序的 map 无序映射统计单词的数量
            // 建 两个 无序映射 统计单词出现的次数 看两个 map 是不是一样 比较 map
            // 从而得到两个数组是不是包含一样的单词

            vector<int> ans;
            for (int i = 0; i + top <= s.length(); i++) {
                if (valid(substr(i, top), words)) {
                    ans.push_back(i);
                }
            }
            return ans;
        }

    private:
        bool volid(string str, vector<string>& words) {
            int k = words[0].length(); // 单个单词的长度，题目中有定义长度相同的单词
            unordered_map<string, int> splitWordsMap; // 以单个单词为长度 切割放入 map
            for (int i = 0; i < str.length(); i += k) {
                // "barfoobar" => ["bar", "foo", "bar"] => {"bar":2, "foo":1}
                splitWordsMap[str.substr(i, k)]++;
            }
            return equalsMap(splitWordsMap, wordsMap);
            // "barfoobar" => ["bar", "foo", "bar"] => {"bar":2, "foo":1}
            // ["foo", "bar", "bar"] => {"foo": 1, "bar": 2}
        }

        bool equalsMap(unordered_map<string, int>& a, unordered_map<string, int>& b) {
            for (auto& key_and_value : a) {
                const string &key = key_and_value.first;
                int value = key_and_value.second;
                if (b.find(key) == b.end() || b[key] != value)
                    return false;
            }
            for (auto& key_and_value : b) {
                const string &key = key_and_value.first;
                int value = key_and_value.second;
                if (a.find(key) == a.end() || a[key] != value)
                    return false;
            }
            return true;
        }
        unordered_map<string, int> wordsMap;
};