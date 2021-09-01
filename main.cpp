#include <iostream>
#include "TwoSum.cc"
#include "CorpFlight.cc"
#include "Reverse.cc"
using namespace std;

int main()
{
    TwoSum two;
    int arr[4] = {2, 2, 2, 7};
    vector<int> ao(arr, arr + 4);
    vector<int> aw;
    aw = two.twoSum1(ao, 9);

    //cout << aw << endl;

    int num = aw.size();

    cout << num << endl;

    for (int i = 0; i < num; i++)
    {
        cout << aw[i] << endl;
    }

    // CorpFlight corp;

    // vector<vector<int>> array;
    
    Reverse re;
    ListNode* one = new ListNode(1);
    ListNode* two_l = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
    ListNode* six = new ListNode(6);
    one->next = two_l;
    two_l->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = NULL;

    cout << re.ReverseList(one)->val << endl;

    return 0;
}