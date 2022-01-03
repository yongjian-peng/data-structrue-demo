#include "../stdc++.h"

class RemoveDuplicates {
public:
    int main() {
        vector<int> nums({1, 1, 2, 3, 3, 5});
        nums = removeDuplicates(nums);
        // cout << s << endl;
        for (int i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }

private:
    vector<int> removeDuplicates(vector<int> &nums)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                nums[s] = nums[i];
                s++;
            }
        }
        return nums;
    }
};