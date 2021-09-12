#include <iostream>
#include "Default.h"

using namespace std;


class Reverse {
    // 递归反转 
    public:
        ListNode* ReverseList(ListNode* head) {
            if(head == NULL || head->next == NULL) {
                return head;
            }    
            ListNode* result = ReverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return result;
        }

    // 反转
    public:
        ListNode* ReverseList2(ListNode* head) {
            ListNode *last = NULL;

            while(head != NULL) {
                //
                ListNode *nextHead = head->next;
                // 移动边
                head->next = last;

                last = head;
                head = nextHead;
            }
            return last;
        }
};



