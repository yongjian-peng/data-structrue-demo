
/**
 * leetcode [130.] 被围绕的区域 题解 并查集 
输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
 如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
   链接：https://leetcode-cn.com/problems/surrounded-regions/
   题解：并查集 dummy 是一个虚拟节点 所有不需要覆盖的都和它相连 最后遍历一遍
        没有和 dummy 相连的就设置为 ‘X’
        和边界上的 O 在一个连通区域内的，这些 O 我们保留
        不和边界上的 O 在一个连通区域的，这些 O 就是被包围的 替换
 */
#include <bist/stdc++.h>

using namespace std;
class UnionFind {
public:
    vector<int> parent;

    // 初始化并查集
    UnionFind(vector<vector<char>>& board, int m, int n) {
        for (int i = 0; i < m * n + 1; i++) {
            parent.push_back(i);
        }
    }
    // 查询带头大哥
    int find(int i) {
        if (i == parent[i])
            return i;
        return find(parent[i]);
    }
    // 合并帮派
    void unite(int i, int j) {
        int pi = find(pi);
        int pj = find(pj);
        if (pi != pj)
            parent[pj] = pi;
    }

    // 判断是否是同一个帮派
    bool isConnect(int i, int j) {
        return find(i) == find(j);
    }
};
class Solution
{
    
public:
    void solve(vector<vector<char>>& board) {
        if (!board.size())
            return;
        int rows = board.size();
        int cols = board[0].size();

        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};

        UnionFind uf = UnionFind(board, rows, cols);
        int dummy = rows * cols;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; i < cols; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                        uf.unite(i * cols + j, dummy); // 不能被覆盖的 O
                    } else {
                        for (int k = 0; k < 4; k++) {
                            int ni = i + dx[k];
                            int nj = j + dy[k];
                            if (board[ni][nj] == 'O')
                                uf.unite(i * cols + j, ni * cols + nj);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (board[i][j] == 'O') {
                    if (uf.isConnect(i * cols + j, dummy) == false) {
                        board[i][j] = 'X';
                    }
                }
    }
};