#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TwoSum2
{
    vector<int> twoSum3(vector<int> &nums, int target) {
        // 定义一个map 来存已经计算过的值
        map<int, int> mp;
        // 定义映射的变量
        vector<int> vs;
        // 数和值的映射
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(target - nums[i]) && mp[target - nums[i]] != i) {
                vs.push_back(i);
                vs.push_back(mp[target - nums[i]]);
                break;
            }
        }
        
    }
}