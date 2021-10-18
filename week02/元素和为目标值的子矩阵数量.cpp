/*
 * leetcode [1074.0 元素和为目标值的子矩阵数量
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
            // 使用前缀和解法 依次扫描以列为单位 的 行的前缀和
            // 和为 key 出现的频率 为 value 的map 中
            int m = matrix.size(), n = matrxi[0].size();

            // 前缀和处理
            for (int i = 0; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] += matrix[i][j - 1];
                }
            }

            // 以列为单位 依次扫描
            for (int k = 0; k < n; k++) {
                for (int j = k; j < n; j++) {
                    int sum = 0;
                    // 操作列中的最小元素
                    // 加入 {0, 1}以0，0为左上角的区间和 等于 target 属于边界情况
                    unordered_map<int, int> mp = {{0, 1}};
                    for (int i = 0; i < m; i++) {
                        // i 每一列中的单个元素 从上到下的行
                        // 计算当前区间的区间和
                        sum += (k == 0 ? matrix[i][j] : matrix[i][j] - matrix[i][j -1]);
                        // x + y = target
                        // 如果 target - y 存在于 hash 表中
                        // 那么 说明有一个区间和为 x 的区间 满足 x + y = target
                        if (mp.count(sum - target)) {
                            ans += mp[sum - target];
                        }
                        mp[sum]++;
                    }
                }
            }
            return ans;
        }
};