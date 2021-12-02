
/**
 * leetcode [547.] 省份数量
输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2

链接：https://leetcode-cn.com/problems/number-of-provinces/
 */
#include <bist/stdc++.h>

using namespace std;
class Trie
{
    /**
     * 题解：使用 并查集  如果相连则是属于一个省份（一个集合中） 判断有多少等于自己的，就是有多少个省份
     */
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 0)
            return 0;
        // makeset
        fa = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++)
            fa[i] = i;
        // 对于每条边 把两个集合合并
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j])
                    unioSet(i, j);
        int ans = 0;
        // 有几棵树，（几个根）就有几个城市
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                ans++;
        }
        return ans;
    }

priveate:
    int find(int x) {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }
    unioSet(int x, int y) {
        x = find(x), y = find(y);
        if (x != y)
            fa[x] = y;
    }

    vector<int> fa;
};