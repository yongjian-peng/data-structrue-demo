/*
 * leetcode [874.] 模拟行走机器人
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
            unordered_set<long, long> obs; // 障碍物
            for (const vector<int>& obstacle : obstacles) {
                // 数组转 string
                obs.insert(calcHans(obstacle));
            }

            int x = 0, y = 0;
            //              北   东    南   西 
            int dir = 0; // N=0, E=1, S=2, W=3

            /*
                        北
                西              东
                        南
                        
                        |
                        |
                  ______|______
                        |
                        |
                        |

            */

            // 定义方向数组     北 东 南 西
            const int dx[4] = {0,1,0,-1};
            const int dy[4] = {1,0,-1,0};
            int ans = 0;
            for (int command : commands) {
                if (command == -1) {
                    dir = (dir + 1) % 4;
                } else if (command == 2) {
                    dir = (dir + 3) % 4;
                } else {
                    for (int i = 0; i < command; i++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        // 如果是障碍物
                        if (obs.find(caclHans({nx, ny})) != obs.end())
                            break;

                        x = nx;
                        y = ny;
                        ans = max(ans, x * x + y * y);
                    }
                }
            }
            return ans;
        }

    private:
        long long caclHans(const vector<int>& obstacle) {
            // return to_string(obstacle[0]) + "," + to_string(obstacle[1]);
            return (obstacle[0] + 30000) * 60001ll + (obstacle[1] + 30000);
        }
};