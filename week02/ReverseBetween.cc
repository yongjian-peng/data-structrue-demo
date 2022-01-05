#include <iostream>
#include "../Default.h"

using namespace std;

class ReverseBetween {
    public:
        int main() {
            //  ---------------- 反转链表 输入 左 右 返回区间内反转 ------------------

            ReverseBetween reb;
            ListNode* one = new ListNode(1);
            ListNode* two = new ListNode(2);
            ListNode* three = new ListNode(3);
            ListNode* four = new ListNode(4);
            ListNode* five = new ListNode(5);
            ListNode *six = new ListNode(6);

            one->next = two;
            two->next = three;
            three->next = four;
            four->next = five;
            five->next = NULL;

            //vector<int> pr = st.printListFromTailToHead(one);
            ListNode* ss = reb.reverseBetween(one, 2, 4);
            ShowList(ss);

            cout << reb.reverseBetween(one, 1, 4) << endl;
            return 0;
        }
        ListNode *reverseBetween(ListNode *head, int left, int right) {
            // 设置 dummyNode 是这一类问题的一般做法
            ListNode *dummyNode = new ListNode(-1);
            dummyNode->next = head;

            // 找到 pre 在链表中的固定位子
            ListNode *pre = dummyNode;
            for (int i = 0; i < left - 1; i++) {
                pre = pre->next;
            }

            ListNode *cur = pre->next;
            ListNode *next;
            for (int i = 0; i < right - left; i++) {
                // 转换 三个变量的位置 pre cur next
                // 寻找next的位置
                next = cur->next;
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
            }

            return dummyNode->next;
        }
};