
/**
 * leetcode [130.] 被围绕的区域 题解 BFS
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
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
            BFS(board, i, 0);
            if (cols > 1)
                BFS(board, i, cols - 1);

        for (int j = 1; j < cols - 1; j++)
            BFS(board, 0, j);
            if (rows > 1)
                BFS(rows - 1, j);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'D')
                    board[i][j] = 'O';
    }

private:
    void BFS(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O')
            return;
        else
            board[i][j] = 'D';

        queue<pair<int, int>> myQueue;
        myQueue.push(make_pair(i, j));
        while (!myQueue.empty()) {
            int x = myQueue.front().first;
            int y = myQueue.front().second;
            myQueue.pop();

            if (x + 1 < rows && board[x + 1][y] == 'O') {
                myQueue.push(make_pair(x + 1, y));
                board[x + 1][y] = 'D';
            }
            if (x - 1 > 0 && board[x - 1][y] == 'O') {
                myQueue.push(make_pair(x - 1, y));
                board[x - 1][y] = 'D';
            }
            if (y + 1 < cols && board[x][y + 1] == 'O') {
                myQueue.push(make_pair(x, y + 1));
                board[x][y + 1] = 'D';
            }
            if (y - 1 > 0 && board[x][y - 1] == 'O') {
                myQueue.push(make_pair(x, y - 1));
                board[x][y - 1] = 'D';
            }
        }
    }

    int rows, cols;
};