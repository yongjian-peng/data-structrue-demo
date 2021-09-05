#include <iostream>
#include "Default.h"

using namespace std;


class Reverse {
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
};



