#include "../stdc++.h"
using namespace std;

class NumberofCattle {
    // 初始只有一头牛。牛只有6年的生命(第0年出生，第6年死去)，牛第3年和第5年会生小牛。问：初始只有一只牛，求第n年牛的个数
    public:
        int main() {
            // 初始只有一头牛。牛只有6年的生命(第0年出生，第6年死去)，牛第3年和第5年会生小牛。问：初始只有一只牛，求第n年牛的个数
            NumberofCattle nc;
            int year = 1;

            vector<int> arr(7, 0);
            arr[0] = 1;

            int current = 15;
            cout << "ab" << endl;
            vector<int> ca = nc.numberofNattle(arr, year, current);
            int ans = 0;

            for (int i : ca)
            {
                ans += i;
            }
            cout << ans << endl;
        };

        vector<int> numberofNattle(vector<int> arr, int year, int current) {
            vector<int> newarr(arr.size() + 1, 0);
            if (current == year) {
                return arr;
            }

            for (int i = 0; i < arr.size() - 1; i++)
            {
                if (i == 0) {
                    newarr[0] = 0;
                } else {
                    newarr[i] = arr[i - 1];
                }
            }
            newarr[0] = newarr[2] + newarr[4];
            newarr[5] = 0;
            return numberofNattle(newarr, year + 1, current);
        }
        
};