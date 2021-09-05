#include <iostream>
#include "Default.h"

using namespace std;

class ReverseBetween {
    public:
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