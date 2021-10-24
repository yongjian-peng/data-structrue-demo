#include "stdc++.h"

using namespace std;

class TreeDiameter {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            n = max(n, max(x, y));
        }
        n++;
        for (int i = 0; i < n; i++)
            to.push_back({});
        for (vector<int> &edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            to[x].push_back(y);
            to[y].push_back(x);
        }
        int p = findFarthest(0).first; // 0 的远 点是哪一个
        return findFarthest(p).second; // 离p 最远的点
    }

private:
    pair<int,int> findFarthest(int start) {
        vector<int> depth(n, -1); // 记录深度 -1 表示还没有算过
        queue<int> q;
        q.push(start);
        depth[start] = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : to[x]) {
                if (depth[y] != -1) {
                    continue; // 走过了
                }
                depth[y] = depth[x] + 1;
                q.push(y);
            }       
        }
        int ans = start;
        // 那个 depth 离起点最远
        for (int i = 0; i < n; i++)
            if (depth[i] > depth[ans])
                ans = i;
        return {ans, depth[ans]};
    }
    int n; // 点数最大的
    vector<vector<int>> to;

};