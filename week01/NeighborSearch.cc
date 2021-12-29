#include "../stdc++.h"
#include "../Default.h"

const int SIZE = 100005;
int a[SIZE], ans[SIZE], rk[SIZE];
NodeL *pos[SIZE];
int n;

// 双链表插入模版，在node后面插入新节点
NodeL *AddNode(NodeL *node, int idx)
{
    NodeL *newNode = new NodeL();
    newNode->val = a[idx];
    newNode->idx = idx;
    node->next->pre = newNode;
    newNode->next = node->next;

    newNode->pre = node;
    node->next = newNode;
    return newNode; // no return
}

// 双链表删除模版
void DeleteNode(NodeL *node)
{
    node->pre->next = node->next;
    node->next->pre = node->pre;
    delete node;
}

class NeighborSearch {
    public:
        int neighborSearch() {
            // ----------- 邻值查找 ---------------
            cin >> n;
            for (int i = 1; i <= n; i++)
            { // i = 0
                scanf("%d", &a[i]);
                rk[i] = i;
            }

            // rk 的 含义：rank[i] 表示排第i名的是谁（是哪个下标）？
            // 有序序列是：a[rk[1]], a[rk[2]], ... a[rk[n]]
            // a = [1, 5, 3, 4, 2]
            // rk = [1     5    3    4    2]
            //      a[1] a[5] a[3] a[4] a[2]
            // a[rk] = [1,  2,  3,   4,   5]
            sort(rk + 1, rk + n + 1, [&](int rki, int rkj)
                 { return a[rki] < a[rkj]; });

            // 保护节点
            NodeL head;
            NodeL tail;
            head.next = &tail;
            tail.pre = &head;
            head.val = a[rk[1]] - 1e9;
            tail.val = a[rk[n]] + 1e9;
            for (int i = 1; i <= n; i++)
            {
                // 数值：a[rk[i]], 下标 rk[i]
                pos[rk[i]] = AddNode(tail.pre, rk[i]);
            }
            for (int i = n; i > 1; i--) {
              NodeL* curr = pos[i];
              // 前驱 后继
              if (a[i] - curr->pre->val <= curr->next->val - a[i]) {
                ans[i] = curr->pre->idx;
              } else {
                ans[i] = curr->next->idx;
              }
              DeleteNode(curr);
            }

            for (int i = 2; i <= n; i++) {
              printf("%d %d\n", abs(a[ans[i]] - a[i]), ans[i]); // a[ans[i] - a[i]]
            }
            return 0;
        }
};
