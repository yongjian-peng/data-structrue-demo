#include <iostream>
#include "../Default.h"

using namespace std;

class ReverseKGroup
{
    public:
        ListNode* reversekGroup(ListNode* head, int k) {
            ListNode* protect = new ListNode(0);
            // 分组 （找到每一组的开始，结尾）按组遍历
            // last = 上一组的结尾
            ListNode* last = protect;

            while(head != NULL) {
                ListNode* end = getEnd(head, k);
                if (end == NULL) {
                    break;
                }
                ListNode* nextGroupHead = end->next;
                // 处理head到end之间的 k-1 条边的反转
                reverseList(head, end);
                // 上一组跟本组的新开始（旧end）建立联系
                last->next = end;
                // 本组的新结尾（head）跟下一组建立联系
                head->next = nextGroupHead;

                // 分组遍历
                last = head;
                head = nextGroupHead;
            }
            
            return protect->next;
        }
        
        ListNode* getEnd(ListNode* head, int k) {
            
            while (head != NULL)
            {
                /* code */
                k--;
                if (k == 0) break;
                head = head->next;
            }
            return head;            
        }
    private:
        void reverseList(ListNode* head, ListNode* end) {
            
            ListNode* last = head;
            head = head->next;
            // 改每条边，所以需要访问链表
            while (head != end)
            {
                ListNode* nextHead = head->next;

                head->next = last;
                // last head 向后移动一位
                last = head;
                head->next = nextHead;
            } 
            end->next = last;
        }
};
