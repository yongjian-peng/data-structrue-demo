#include "stdc++.h"

using namespace std;

class NumberofCattle {
    // 初始只有一头牛。牛只有6年的生命(第0年出生，第6年死去)，牛第3年和第5年会生小牛。问：初始只有一只牛，求第n年牛的个数
    public:
        int numberofNattle(int year) {
            // 牛数量 年龄
            unordered_map<int, int> cattles;
            this->year = year;
            cattles[0] = 1; // 期初一头牛
            cattles[1] = 0;
            cattles[2] = 0;
            cattles[3] = 0;
            cattles[4] = 0;
            cattles[5] = 0;
            // ans = 1;
            unordered_map<int, int> ans;
            ans = bfs(cattles, 0); // 从第一年开始
            return ans[1];
        }

    private:
        unordered_map<int, int> bfs(unordered_map<int, int>& cattles, int current)
        {
            // cout << year << endl;
            unordered_map<int, int> new_cattles;
            if (year == current)
                return cattles;
            for (int i = 0; i < 6; i++) {
                if (i == 0)
                {
                    new_cattles[0] = 0;
                }
                else
                {
                    
                    new_cattles[i] = cattles[i - 1];
                }
            }

            new_cattles[0] = new_cattles[2] + new_cattles[4];
            new_cattles[5] = 0;
            return bfs(new_cattles, current + 1);
        }
        int ans;
        int year;
        
};