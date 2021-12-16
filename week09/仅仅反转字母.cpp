
/**
 * leetcode [917.] 仅仅反转字母
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
链接：https://leetcode-cn.com/problems/reverse-only-letters/
 */
#include <bist/stdc++.h>

using namespace std;
class Trie
{
    /**
     * 题解：双指针扫描
     * 
     */
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j) {
            while(i < n && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
                ++i;
            while (j >= 0 && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')))
                --j;
            
            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};