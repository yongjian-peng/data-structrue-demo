
/**
 * leetcode [130.] 被围绕的区域 题解 DFS
输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
 如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
   链接：https://leetcode-cn.com/problems/surrounded-regions/
   题解：广度优先搜索
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
            DFS(board, i, 0);
        if (cols > 1)
            DFS(board, i, cols - 1);

        for (int j = 1; j < cols - 1; j++)
            DFS(board, 0, j);
        if (rows > 1)
            DFS(rows - 1, j);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
        if (board[i][j] == 'D')
            board[i][j] = 'O';
    }

private:
    void DFS(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] == 'X' || board[i][j] == 'D')
            return;

        if (board[i][j] == 'O')
            board[i][j] = 'D';

        DFS(board, i - 1, j);
        DFS(board, i + 1, j);
        DFS(board, i, j - 1);
        DFS(board, i, j + 1);
    }

    int rows, cols;
};