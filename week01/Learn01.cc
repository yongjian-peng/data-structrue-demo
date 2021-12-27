#include "../Trap.cc"
// #include "../LargestRectangleArea2.cc"
using namespace std;

class Learn01 {
    public:
        int learn01() {
            // 横条解题 单调栈
            Trap trap;
            LargestRectangleArea2 lra2;
            int heights[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
            vector<int> hei(heights, heights + 12);
            cout << trap.trap(hei) << endl;
            // 竖条解题 维护前缀 后缀 最大值
            cout << trap.trapheight(hei) << endl;
            return 0;
        }
};