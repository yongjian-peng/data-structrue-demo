
/**
 * leetcode [1143.] 单词搜索2
输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
输出：["eat","oath"]

链接：https://leetcode-cn.com/problems/word-search-ii/
 */
#include <bist/stdc++.h>

using namespace std;
class Solution
{
    /**
     * 题解：使用 trid 树 搜索引擎中的智能提示 功能补全功能
     * 
     */
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        // 建立 Trie 插入 Words
        for (const string& word : words) {
            insert(word);
        }

        // 2. 枚举每个起点 搜索
        m = board.size();
        n = board[0].size();

        visit = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visit[i][j] = true;
                dfs(board, i, j, root);
                visit[i][j] = false;
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }

private:
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};

    struct Node {
        int count;
        unordered_map<char, Node*> child;
        Node(): count(0) {}
    };
    Node* root;
    int m, n;
    vector<vector<bool>> visit;
    string str;
    unordered_set<string> ans;

    void dfs(vector<vector<char>>& board, int x, int y, Node*  curr) {
        if (curr == nullptr)
            return;
        char ch = board[x][y];
        if (curr->child.find(ch) == curr->child.end())
            return;
        Node *next = curr->child[ch];

        str.push_back(ch);
        if (next->count > 0)
            ans.insert(str);
        if (next->child.empty()) {
            curr->child.erase(ch);
            delete next;
        } else {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >=y)
                    continue;
                if (visit[nx][ny])
                    continue;
                visit[nx][ny] = true;
                dfs(board, nx, ny, next);
                visit[nx][ny] = false;
            }
        }
        str.pop_back();
    }

    void insert(const string& s) {
        Node* curr = root;
        for (char c : s) {
            if (curr->child.find(c) == curr->child.end()) {
                curr->child[c] = new Node();
            }
            curr = curr->child[c];
        }
        curr->count++;
    }
};