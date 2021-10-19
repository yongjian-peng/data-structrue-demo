/*
 * leetcode [77.] 组合
 示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        this->n = k;
        this->k = k;
        recur(1);
        return ans;
    }

private:
    void recur(int i)
    {
        // 剪枝 如果已经选了超过k个 或者说选剩下的全部也不够k个 说明肯定不合法了 提前退出
        if (chosen.size() > k || chosen.size() + (n - i + 1) < k)
            return;
        if (i == n + 1)
        {
            ans.push_back(chosen);
            return;
        }
        recur(i + 1);
        chosen.push_back(i);
        recur(i + 1);
        chosen.pop_back(i);
    }

    int n, k;
    vector<int> chosen;
    vector<vector<int>> ans;
};