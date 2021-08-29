#include <iostream>
#include <vector>
#include <map>
using namespace std;
class TwoSum
{
public:
    vector<int> twoSum1(vector<int> &nums, int target)
    {
        vector<int> vec;
        map<int, int> dic;
        for (int i = 0; i < nums.size(); i++)
        {
            dic[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (dic.count(target - nums[i]) && dic[target - nums[i]] != i)
            {
                vec.push_back(i);
                vec.push_back(dic[target - nums[i]]);
                break;
            }
        }
        return vec;
    }
};