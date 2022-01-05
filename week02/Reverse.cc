#include <iostream>
#include "../Default.h"

#include "ReverseKGroup.cc"

using namespace std;


class Reverse {

    // 递归反转 
    public:
        int main() {
            // ----------------- 链表 ------------------
            Reverse re;

            ReverseKGroup reg;
            ListNode* one = new ListNode(1);
            one->next = new ListNode(2);
            one->next->next = new ListNode(3);
            one->next->next->next = new ListNode(4);
            one->next->next->next->next = new ListNode(5);
            one->next->next->next->next->next = new ListNode(6);
            one->next->next->next->next->next->next = new ListNode(7);
            one->next->next->next->next->next->next->next = new ListNode(8);

            re.ReverseList2(one);
            reg.reversekGroup(one, 2);

            cout << re.ReverseList2(one)->val << endl;

            ShowList(re.ReverseList2(one));

            ShowList(reg.reversekGroup(one, 2));
            return 0;
        }
        ListNode* ReverseList(ListNode* head) {
            if(head == NULL || head->next == NULL) {
                return head;
            }    
            ListNode* result = ReverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return result;
        }

        ListNode *ReverseList2(ListNode *head)
        {
            ListNode *last = NULL;

            while (head != NULL)
            {
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



