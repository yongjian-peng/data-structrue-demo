
/**
 * leetcode [208.] 实现Trie(前缀树)
输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true

链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
 */
#include <bist/stdc++.h>

using namespace std;
class Trie
{
    /**
     * 题解：使用 trid 树
     * 
     */
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        find(word, true, true);
    }

    bool search(string word) {
        return find(word, true, false);
    }

    bool startsWith(string prefix) {
        return find(prefix, false, false);
    }

private:
    struct Node {
        int count;
        unordered_map<char, Node*> child;
        Node(): count(0) {}
    };

    Node *root;
    bool find(const string& s, bool exact_match, bool insert_if_not_exist) {
        Node *curr = root;
        for (char c : s) {
            if (curr->child.find(c) == curr->child.end()) {
                if (!insert_if_not_exist)
                    return false;
                curr->child[c] = new Node();
            }
            curr = curr->child[c];
        }
        if (insert_if_not_exist)
            curr->count++;
        return exact_match ? curr->count > 0 : true;
    }
};