#include "stdc++.h"

using namespace std;

class NumberofCattle {
    // 初始只有一头牛。牛只有6年的生命(第0年出生，第6年死去)，牛第3年和第5年会生小牛。问：初始只有一只牛，求第n年牛的个数
    public:
        int numberofNattle(int n) {      
            this->n = n; 
            cattles[1] = 1; // 期初一头牛
            ans = 1;
            bfs(ans,0); // 从第一年开始    
            return ans;
        }

    private:
        void bfs(int ans, int year) {
            // cout << year << endl;
            if (year == n)
                return;

            for (auto cattle : cattles) {  
                // 牛的年龄 第六年死去
                int ci = cattle.first;
                int age = cattle.second;      
                if (age = 6) {
                    cattles.erase(ci); // 删除掉 
                    ans--;
                }         
                    
                cattles[ci]++; // 加年龄
                if (age == 3 || age == 5) {
                    ans++; //
                    jia++;
                    cattles[ans] = 1;// 出生的小牛
                    cout << ans << endl;
                    bfs(ans, year + 1);   
                }
            }
                
        }
        int jia = 1;
        int ans;
        int n;
        // 牛数量 年龄 
        unordered_map<int, int> cattles;
};