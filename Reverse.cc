#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {

        }
    /* data */
};

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



