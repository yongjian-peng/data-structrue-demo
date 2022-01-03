#include "../stdc++.h"

class MergeTwoArray {
    public:
        int main() {
            vector<int> nums1({1,2,3,0,0,0} );
            int m = 3;
            vector<int> nums2({2, 5, 6} );
            int n = 3;
            mergeTwoArray(nums1, m, nums2, n);

            for(int i : nums1) {
                cout << i << endl;
            }
            return 0;
        }
    private:
        void mergeTwoArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // 合并两个数组 倒序排序 可以节省一个数组的拷贝
            int i = m - 1;
            int j = n - 1;
            for (int k = m + n - 1; k >= 0; k--) {
                // 判断是否越界
                if (j < 0 || (i >= 0 && nums1[i] >= nums2[j])) {
                    nums1[k] = nums1[i];
                    i--;
                } else {
                    nums1[k] = nums2[j];
                    j--;
                }
            }
        }
};