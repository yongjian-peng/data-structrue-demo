
/*
 * leetcode [51.] N 皇后
输入 1: 迷宫由以下二维数组表示

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

输入 2: 起始位置坐标 (rowStart, colStart) = (0, 4)
输入 3: 目的地坐标 (rowDest, colDest) = (3, 2)

输出: false

链接：https://leetcode-cn.com/problems/the-maze/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 

public:
    int dir[2][4] = {{0,0,1,-1},{1,-1,0,0}};
    int maxx, maxy, dex, dey;
    bool vis[105][105] = {0};
    inline bool legal(int x, int y) {
        return (x >= 0 && y >= 0 && x < maxx && y < maxy);
    }
    
    bool hasPaht(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        dex = destination[0], dey = destination[1];
        maxx = maze.size(), maxy = maze[0].size();
        return dfs(start[0], start[1], maze);
    }

    inline bool dfs(int x, int y, vector<vector<int>>& graph) {
        vis[x][y] = 1; // 已经访问过改节点
        if (x == dex && y == dey) // 可以到达目的地
            return true;
        for (int i = 0; i < 4; i++) {
            int tempx = x + dir[0][i];
            int tempy = y + dir[1][i];
            // 沿着某个方向走到靠墙的点
            while (legal(tempx, tempy) && graph[tempx][tempy] != 1){
                tempx += dir[0][i];
                tempy += dir[1][i];
            }
            tempx -= dir[0][i]; // 回溯到最后合法的靠墙点
            tempy -= dir[1][i];

            if (vis[tempx][tempy])
                continue;
            if (dfs(tempx, tempy, graph)) // 没有访问就继续搜索
                return true; // 已经可以到达目的地，
        }
        return false; // 所有方向都无法到达目的地

    }
};