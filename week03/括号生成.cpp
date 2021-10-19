/*
 * leetcode [22.] 括号生成
 示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {""};
        if (store.find(n) != store.end())
            return store[n];
        vector<string> ans;
        for (int k = 0; k <= n; k++)
        {
            vector<string> A = generateParenthesis(n - 1);
            vector<string> B = generateParenthesis(n - k);
            for (string& a : A)
                for (string& b : B)
                    ans.push_back('(' + a ')' + b);


        }
        store[n] = ans;
        return ans;
    }

private:
    unordered_map<int, vector<string>> store; // 记忆存储

    /*
       ((()))
       (()())

       (())()
       ()(())

       ()()()

       S(A)B
       n k-1 n-k

       k = 1.  (A)   A=0对括号   (). B=n-k=2对括号。  ()() (())
             ()()() ()(())
       k = 2.  (A)   A=1对括号  (()). B=n-k=1对括号。  ()
             (())()
       k = 3.  (A)   A=2对括号  (()()) ((())). B=n-k=0对括号。  空{}
             (()())((()))

   */
};