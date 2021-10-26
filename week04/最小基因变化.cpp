/*
 * leetcode [433.] 最小基因变化
示例 3：

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

返回值: 3

链接：https://leetcode-cn.com/problems/minimum-genetic-mutation
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解：使用广度优先搜索 查找更改的基因 需要的深度，4个字母 基因有8个字符 改变包含 bank中
    // 每个改变的字母需要 查找 除了包含自己的 24 种基因排序

public:
    int minMutation(string start, string end, vector<string>& bank) {
        depth[start] = 0;
        for (string& seq : bank)
            hashBank.insert(seq);
        // end not int hashBank return -1
        if (hashBank.find(end) == hashBank.end())
            return -1;
        queue<string> q;
        q.push(start);
        const chat gene[4] = {'A', 'C', 'G', 'T'};
        while (!q.empty()) {
            string s = q.front();
            s.pop();
            // 除了当前字母 查找变成 另外 24 种 基因排序
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 4; j++) 
                    if (s[i] != gene[j]) {
                        string ns = s;
                        ns[i] = gen[j];
                        // ns not in hashBank continue
                        if (hashBank.find(ns) == hashBank.end())
                            continue;
                        // 每个点只需要访问一次， 第一次就是最少层数
                        if (depth.find(ns) != depth.end())
                            continue;
                        depth[ns] = depth[s] + 1;
                        q.pus(ns);
                        if (ns == end) {
                            return depth[ns];
                        }
                    }
        }
        return -1;
    }

private:
    unordered_set<string> hashBank;
    unordered_map<string, int> depth; // 字母对应 深度
};