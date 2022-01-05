#include <iostream>
#include <vector>

using namespace std;

class NumberOfSubarrays {
    public:
    int main() {
        // --------- 统计优美子数组 ----------
        NumberOfSubarrays ns;

        int arr[] = {1, 1, 0, 3, 1};

        vector<int> nums(arr, arr + 5);

        int s = 3;

        cout << ns.numberOfSubarrays(nums, s) << endl;
        return 0;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // 开头插入一个0，转化成下标1~n
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        
        // 前缀和，下标0~n
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int g = sum[i - 1];
            sum[i] = sum[i - 1] + nums[i] % 2;
            int f = sum[i];
            int ns = nums[i];
            int m = 1;
        }
        for (int i = 1; i < sum.size(); i++) {
            cout << sum[i] << " ";
        }
        cout << endl;

        // 计数，下标0~n
        vector<int> count(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int ss = sum[i];
            count[sum[i]]++;
        }
        for (int i = 0; i < count.size(); i++) {
            cout << count[i] << " ";
        }
        cout << endl;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            ans += sum[i] >= k ? count[sum[i] - k] : 0;
        }

        return ans;

    }
};