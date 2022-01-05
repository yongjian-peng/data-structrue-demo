#include <iostream>
#include <vector>
#include <map>
using namespace std;
class TwoSum
{
public:
    int main() {
          TwoSum two;
        int arr[4] = {2, 2, 2, 7};
        vector<int> ao(arr, arr + 4);
        vector<int> aw;
        aw = two.twoSum1(ao, 9);

        //cout << aw << endl;

        int num = aw.size();

        cout << num << endl;

        for (int i = 0; i < num; i++)
        {
            cout << aw[i] << endl;
        }
        return 0;
    }
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
            // map count 返回的是被查找元素的个数
            int ss = dic.count(target - nums[i]);
            int a = ss;
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