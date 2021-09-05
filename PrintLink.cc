#include <stack>
#include <vector>
#include "Default.h"

using namespace std;

class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        std::stack<ListNode *> nodes;
        std::vector<int> result;
        ListNode *pnode = head;
        while (pnode != nullptr)
        {
            nodes.push(pnode);
            pnode = pnode->next;
        }
        while (!nodes.empty())
        {
            result.push_back(nodes.top()->val);
            nodes.pop();
        }
        return result;
    }
};