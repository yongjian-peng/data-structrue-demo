/*
 * leetcode [23.] 合并K个升序链表
 输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Definition for singly-linked list
    // struct ListNode
    // {
    //     int val;
    //     ListNode *next;
    //     ListNode() : val(0), next(nullptr) {}
    //     ListNode(int x) : val(x), next(nullptr) {}
    //     ListNode(int x, ListNode *next) : val(x), next(next) {}
    // }; 分治思想解法 可以使用 堆来维护，比较快

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l ==r) {
            return lists[l];
        }
        if (l > r) {
            return nullptr;
        }
        int mid = (l + r) >> 1; // 分治解法 左边到中间点  中间点到右边
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    // 合并两个数组
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if ((!a) || (!b))
            return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }

        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }
};