
/*
 * leetcode [210.] 课程表 II
 输入：lists = [[1,4,5],[1,3,4],[2,6]]
输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
输出：[0,2,1,3]
解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。

链接：https://leetcode-cn.com/problems/course-schedule-ii
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // 题解：使用拓扑排序 + 队列 queue BFS 广度优先搜索 出边数组

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequistites) {
        to = vector<vector<int>>(numCourses, vector<int>());
        inDeg = vector<int>(numCourses, 0);
        for (vector<int>& pre : prerequistites) {
            int ai = pre[0];
            int bi = pre[1];
            to[bi].push_back(ai);
            to[ai].push_back(bi);
            inDeg[ai]++; // 增加数组的入度
        }

        queue<int> q;
        // 从拓扑排序第一步：从零度出发
        for (int i = 0; i < numCourses; i++) {
            if (isDeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> lessons;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            lessons.push_back(x);
            // 第二步：扩展一个点，周围的点入度减一
            for (int y : to[x]) {
                inDeg[y]--;
                // 第三步：入度为0，表示可以入对了，
                if (isDeg[y] == 0) {
                    q.push(y);
                }
            }
        }

        if (lessons.size() == numCourses) {
            return lessons;
        }
        return {};
    }

private:
    vector<int> inDeg; // 数组元素的入度
    vector<vector<int>> to; // 出边数组
};