/**
 * @file 反转链表.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-26
 *
 * @copyright Copyright (c) 2021
 * leetcode [206.] 反转链表
 * 输入：head = [1,2,3,4,5]
    输出：[5,4,3,2,1]

 */

#include "<bits/stdc++.h>"

using namespace std;

class reverseList {
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */
public:
    ListNode *reverseList(ListNode* head) {
        ListNode *last = nullptr;
        while (head != nullptr) {
            ListNode *headNext = head->next;
            head->next = last;
            last = head;

            head = headNext;
        }
        return last;
    }
};