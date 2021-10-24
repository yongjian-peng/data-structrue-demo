#include <iostream>
#include "TwoSum.cc"
#include "CorpFlight.cc"
#include "Reverse.cc"
#include "FindLAC.cc"
#include "Heapify.cc"
#include "ReverseBetween.cc"
#include "PrintLink.cc"
//#include "Default.h"
#include "KthLargest.cc"
#include "HeapSorti.cc"
#include "MergeArray.cc"
#include "PushZerosToEnd.cc"
#include "ReverseKGroup.cc"
#include "NumberOfSubarrays.cc"
#include "LearnStack.cc"
#include <cstdlib>
#include <queue>
#include <deque>
#include "stdc++.h"
#include "Calculate.cc"
#include "LargestRectangleArea.cc"
#include "Trap.cc"
#include "LargestRectangleArea2.cc"
#include "LargestRectangleArea3.cc"
#include "MaximalRectangle.cc"
#include "MapDemo.cc"
#include "HashMap.cc"
#include "TreeDiameter.cc"

using namespace std;



const int SIZE = 100005;
int a[SIZE], ans[SIZE], rk[SIZE];
NodeL* pos[SIZE];
int n;

// 双链表插入模版，在node后面插入新节点
NodeL* AddNode(NodeL *node, int idx)
{
  NodeL* newNode = new NodeL();
  newNode->val = a[idx];
  newNode->idx = idx;
  node->next->pre = newNode;
  newNode->next = node->next;

  newNode->pre = node;
  node->next = newNode;
  return newNode; // no return 
}

// 双链表删除模版
void DeleteNode(NodeL* node)
{
  node->pre->next = node->next;
  node->next->pre = node->pre;
  delete node;
}

int main()
{
  // ---------- 树的直径 ---------

  vector<vector<int>> edges;

  vector<int> edge;
  edge.push_back(0);
  edge.push_back(1);
  edges.push_back(edge);

  edge = vector<int>();
  edge.push_back(1);
  edge.push_back(2);
  edges.push_back(edge);

  edge = vector<int>();
  edge.push_back(2);
  edge.push_back(3);
  edges.push_back(edge);

  edge = vector<int>();
  edge.push_back(1);
  edge.push_back(4);
  edges.push_back(edge);

  edge = vector<int>();
  edge.push_back(4);
  edge.push_back(5);
  edges.push_back(edge);

  TreeDiameter td;
  int i = td.treeDiameter(edges);

  cout << i << endl;
  // ----------- 自己实现 unordered_map ------------

  // HashMap<int, int, HashFunc> hashmap(10);
  // hashmap.insert(1, 1);
  // hashmap.insert(11, 5);
  // hashmap.print();
  // cout << "----------" << endl;
  // hashmap.insert(2, 8);
  // int num = 1;
  // hashmap.del(num);//删除键值为1的
  // hashmap.print();
  // system("pause");

  // HashMap<int, string> map;
  // map.insert({1010, "wu"});
  // map.insert({1020, "fan"});
  // map.insert({1030, "love"});
  // map.insert({1040, "yan"});
  // map.insert({1050, "han"});

  // cout << map[1030] << endl;
  // // map.erase(1010);
  // Pair<int, string> *it = map.find(1010);
  // if (it == nullptr)
  // {
  //   cout << "not find" << endl;
  // }
  // else
  // {
  //   cout << it->first << endl;
  // }

  // ---------- learn unordered_set unordered_map ------------
  // MapDemo md;
  // md.main();

  // ------------- 二维矩阵最大矩形 ------------

  // ----------- 接雨滴 ---------------
  // 横条解题 单调栈
  // Trap trap;
  // LargestRectangleArea2 lra2;
  // int heights[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // vector<int> hei(heights, heights + 12);
  // cout << trap.trap(hei) << endl;
  // // 竖条解题 维护前缀 后缀 最大值
  // cout << trap.trapheight(hei) << endl;

  // cout << lra2.largestRectangleArea2(hei) << endl;
  // ----------- 柱状图中最大矩形 ----------
  // LargestRectangleArea lra;
  // int heights[] = {2, 1, 5, 6, 2, 3};
  // vector<int> hei(heights, heights + 6);
  // cout << lra.largestReactangleArea(hei) << endl;

  // LargestRectangleArea3 Lra3;
  // int heights2[] = {2, 1, 5, 6, 2, 3};
  // vector<int> hei2(heights2, heights2 + 6);
  // cout << Lra3.largestRectangleArea3(hei2) << endl;

  // ----------- 计算器 ------------
  // Calculate cal;
  // string s = " 2-1 + 2 ";

  // cout << cal.calculat(s) << endl;
  // cout << "hsh" << endl;
  // ----------- 邻值查找 ---------------
  // cin >> n;
  // for (int i = 1; i <= n; i++) { // i = 0
  //   scanf("%d", &a[i]);
  //   rk[i] = i;
  // }

  // rk 的 含义：rank[i] 表示排第i名的是谁（是哪个下标）？
  // 有序序列是：a[rk[1]], a[rk[2]], ... a[rk[n]]
  // a = [1, 5, 3, 4, 2]
  // rk = [1     5    3    4    2]
  //      a[1] a[5] a[3] a[4] a[2]
  // a[rk] = [1,  2,  3,   4,   5]
  // sort(rk + 1, rk + n + 1, [&](int rki, int rkj) { return a[rki] < a[rkj]; });

  // // 保护节点
  // NodeL head;
  // NodeL tail;
  // head.next = &tail;
  // tail.pre = &head;
  // head.val = a[rk[1]] - 1e9;
  // tail.val = a[rk[n]] + 1e9;
  // for (int i = 1; i <= n; i++) {
  //   // 数值：a[rk[i]], 下标 rk[i]
  //   pos[rk[i]] = AddNode(tail.pre, rk[i]);
  // }
  // for (int i = n; i > 1; i--) {
  //   NodeL* curr = pos[i];
  //   // 前驱 后继
  //   if (a[i] - curr->pre->val <= curr->next->val - a[i]) {
  //     ans[i] = curr->pre->idx;
  //   } else {
  //     ans[i] = curr->next->idx;
  //   }
  //   DeleteNode(curr);
  // }

  // for (int i = 2; i <= n; i++) {
  //   printf("%d %d\n", abs(a[ans[i]] - a[i]), ans[i]); // a[ans[i] - a[i]]
  // }

  // ----------- Learn priority_queue 优先队列 ---------------
  // 对于基础类型，默认时大顶堆
  // priority_queue<int> a;
  // // 等同于 priority_queue<int, vector<int>, less<int> > a;

  // priority_queue<int, vector<int>, greater<int> > c; // 这样就是小顶堆
  // priority_queue<string> b;

  // for (int i = 0; i < 5; i++) {
  //   a.push(i);
  //   c.push(i);
  // }

  // while (!a.empty()) {
  //   cout << a.top() << " ";
  //   a.pop();
  // }
  // cout << "\n" << endl;

  // while(!c.empty()) {
  //   cout << c.top() << " ";
  //   c.pop();
  // }
  // cout << "\n"
  //      << endl;

  // b.push("abc");
  // b.push("abcd");
  // b.push("cbc");

  // while(!b.empty()) {
  //   cout << b.top() << " ";
  //   b.pop();
  // }
  // cout << "\n"
  //      << endl;

  // pair 的比较，先比较第一个元素，第一个相等比较第二个
  // priority_queue<pair<int, int> > a;
  // pair<int, int> b(1, 2);
  // pair<int, int> c(1, 3);
  // pair<int, int> d(2, 5);
  // a.push(d);
  // a.push(c);
  // a.push(b);
  // while (!a.empty()) {
  //   cout << a.top().first << " " << a.top().second << "\n";
  //   a.pop();
  // }

  // 对于自定义类型
  // tmp1 a(1);
  // tmp1 b(2);
  // tmp1 c(3);
  // priority_queue<tmp1> d;
  // d.push(b);
  // d.push(c);
  // d.push(a);

  // while(!d.empty()) {
  //   cout << d.top().x << " ";
  //   d.pop();
  // }
  // cout << "\n"
  //      << endl;

  // priority_queue<tmp1, vector<tmp1>, tmp2> f;
  // f.push(c);
  // f.push(b);
  // f.push(a);
  // while (!f.empty()) {
  //   cout << f.top().x << " ";
  //   f.pop();
  // }
  // cout << endl;

  // ----------- deque 双端队列 -----------
  // 是由一段一段的定量连续空间构成，可以向两端发展，因此不论在尾部或头部安插元素都十分迅速
  // 在中间安插元素则比较费时，因为必须移动其他元素
  //  创建和初始化
  // deque<int> dq;
  // deque<int> dq1(8);
  // deque<int> dq2(8, 50);
  // deque<int> dq3(dq2.begin(), dq2.end());
  // deque<int> dq4(dq3);

  // cout << "dq output:";
  // for (auto i : dq)
  //   cout << i << ", ";
  // cout << "\n";

  // cout << "dq1 output: ";
  // for (auto i : dq1)
  //   cout << i << ", ";
  // cout << "\n";

  // cout << "dq2 output: ";
  // for (auto i : dq2)
  //   cout << i << ", ";
  // cout << "\n";

  // cout << "dq3 output: ";
  // for (auto i : dq3)
  //   cout << i << ", ";
  // cout << "\n";

  // cout << "dq4 output: ";
  // for (auto i : dq4)
  //   cout << i << ", ";
  // cout << "\n";

  // ------- 成员函数 新增 --------
  // deque<int> dq;
  // deque<int> dq1(1, 50);
  // int a = 30;

  // // 末尾追加
  // dq.push_back(10); // 10
  // dq.push_back(20); // 10, 20
  // // 头部追加
  // dq.push_front(5); // 5, 10, 20
  // // 末尾追加 copy
  // dq.push_back(a); // 5, 10, 20, 30
  // a = 40;
  // // 末尾追加 moved
  // dq.push_back(move(a)); // 5, 10, 20, 30, 40

  // cout << "dq output: ";
  // for (auto i : dq)
  //   cout << i << ", ";
  // cout << "\n";

  // // deque<int>::iterator it = dq.begin();
  // auto it = dq.begin();
  // ++it;
  // // 在指定的迭代 position 前进行插入新元素
  // dq.insert(it, 6); // 5, 6, 10, 20, 30, 40
  // // 在指定的迭代 position 前插入2个元素 值都为 7
  // dq.insert(it, 2, 7); // 5, 6, 7, 7, 10, 20, 30, 40
  // dq1.push_back(60); // 50, 60
  // dq1.push_back(70); // 50, 60, 70
  // // 在指定的迭代 position 前指定一个迭代器的范围进行插入
  // dq.insert(it, dq1.begin(), dq1.end());
  // cout << "dq output: ";
  // for (auto i : dq)
  //   cout << i << ", ";
  // cout << "\n";

  // ------- 成员函数 删除 --------
  // deque<int> dq;
  // for (int i = 0; i < 10; i++) {
  //   dq.push_back(i); // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  // }
  // dq.pop_front(); // 1, 2, 3, 4, 5, 6, 7, 8, 9
  // dq.pop_back();  // 1, 2, 3, 4, 5, 6, 7, 8
  // dq.erase(dq.begin() + 2); // 1, 2, 4, 5, 6, 7, 8
  // dq.erase(dq.begin() + 2, dq.end() - 2); // 1, 2, 7, 8

  // for (auto i : dq)
  //   cout << i << ", ";
  // cout << "\n";
  // ------- 成员函数 遍历 --------
  // deque<int> dq;
  // for (int i = 0; i < 10; i++) {
  //   dq.push_back(i);
  // }

  // deque<int>::iterator it = dq.begin();
  // for (it; it != dq.end(); it++) {
  //   cout << *it << " ";
  // }
  // cout << "\n";

  // ------- 成员函数 其他 at front back size max_size resize --------
  // deque<int> dq;
  // dq.push_back(10); // 10
  // dq.push_back(20); // 10, 20
  // cout << dq.size() << endl; // 2
  // dq.front() = 100; // 引用重新赋值 10 -> 20
  // dq.back() = 200; // 引用重新赋值 20 -> 200
  // for (int i = 0; i < dq.size(); i++) {
  //   cout << dq.at(i) << " ";
  // }
  // cout << "\n";

  // for (auto i : dq)
  //   cout << i << " ";
  // cout << "\n";
  // dq.resize(5);
  // ---------- learn queue -------------
  // int e, n, m;
  // queue<int> q1;

  // for (int i = 0; i < 10; i++) {
  //   q1.push(i); // 将元素入队
  // }
  // if(!q1.empty()) {
  //   cout << "queue is not empty\n";
  // }
  // n = q1.size();

  // cout << n << endl;

  // m = q1.back(); // 取队尾元素

  // cout << m << endl;

  // for (int j = 0; j < n; j++) {
  //   e = q1.front(); // 取队首元素
  //   cout << e << " ";
  //   q1.pop(); // 将元素出队
  // }

  // cout << endl;
  // if (q1.empty())
  //   cout << "queue is empty\n";
  // system("PAUSE");

  // ----------- Learn Stack ------------
  // try {
  //   Stack<int> intStack; // int 类型的栈
  //   Stack<string> stringStack; // string 类型的栈

  //   // 操作 int 类型的栈
  //   intStack.push(7);
  //   cout << intStack.top() << endl;

  //   // 操作 String 类型的栈
  //   stringStack.push("Hello");

  //   cout << stringStack.top() << endl;
  //   stringStack.pop();
  //   stringStack.pop();
  // } catch (exception const& ex) {
  //   cerr << "Exception:" << ex.what() << endl;
  //   return -1;
  // }

  // --------- 统计优美子数组 ----------
  // NumberOfSubarrays ns;

  // int arr[] = {1, 1, 0, 3, 1};

  // vector<int> nums(arr, arr + 5);

  // int s = 3;

  // cout << ns.numberOfSubarrays(nums, s) << endl;
  //   TwoSum two;
  // int arr[4] = {2, 2, 2, 7};
  // vector<int> ao(arr, arr + 4);
  // vector<int> aw;
  // aw = two.twoSum1(ao, 9);

  // //cout << aw << endl;

  // int num = aw.size();

  // cout << num << endl;

  // for (int i = 0; i < num; i++)
  // {
  //     cout << aw[i] << endl;
  // }

  // CorpFlight corp;

  // vector<vector<int>> array;

  // ----------------- 链表 ------------------
  // Reverse re;

  // ReverseKGroup reg;
  // ListNode* one = new ListNode(1);
  // one->next = new ListNode(2);
  // one->next->next = new ListNode(3);
  // one->next->next->next = new ListNode(4);
  // one->next->next->next->next = new ListNode(5);
  // one->next->next->next->next->next = new ListNode(6);
  // one->next->next->next->next->next->next = new ListNode(7);
  // one->next->next->next->next->next->next->next = new ListNode(8);

  // re.ReverseList2(one);
  //  reg.reversekGroup(one, 2);

  // cout << re.ReverseList2(one)->val << endl;

  // ShowList(re.ReverseList2(one));

  // ShowList(reg.reversekGroup(one, 2));

  // --------------- 树 链表 ---------------
  // Node * root = newNode(1);
  // root->left = newNode(2);
  // root->right = newNode(3);
  // root->left->left = newNode(4);
  // root->left->right = newNode(5);
  // root->right->left = newNode(6);
  // root->right->right = newNode(7);

  // cout << "LCA(4,7) = " << findLCA_H(root, 4,7)->key;

  // int arr[] = { 12, 11, 13, 5, 6, 7 };

  // int n = sizeof(arr) / sizeof(arr[0]);

  // heapSort(arr, n);

  // cout << "Sorted array is \n";
  // printArray(arr, n);

  //  ---------------- 反转链表 输入 左 右 返回区间内反转 ------------------
  // Solution st;

  // ReverseBetween reb;
  // ListNode* one = new ListNode(1);
  // ListNode* two = new ListNode(2);
  // ListNode* three = new ListNode(3);
  // ListNode* four = new ListNode(4);
  // ListNode* five = new ListNode(5);
  // ListNode *six = new ListNode(6);

  // one->next = two;
  // two->next = three;
  // three->next = four;
  // four->next = five;
  // five->next = NULL;

  // //vector<int> pr = st.printListFromTailToHead(one);
  // ListNode* ss = reb.reverseBetween(one, 2, 4);
  // ShowList(ss);

  // cout << reb.reverseBetween(one, 1, 4) << endl;

  // ------ 堆排序 ---------
  // int arr[] = {12, 11, 13, 5, 6, 7};
  // int n = sizeof(arr) / sizeof(arr[0]);

  // heapSort(arr, n);

  // cout << "Sorted array is \n";
  // printArray(arr, n);

  // -------- 动态查找 第 k 大元素 ----------
  /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
  // Node *root = NULL;
  // root = insert(root, 50);
  // insert(root, 30);
  // insert(root, 20);
  // insert(root, 40);
  // insert(root, 70);
  // insert(root, 60);
  // insert(root, 80);

  // int c = 0;
  // kthLargest(root, 6);
  // for (int k = 1; k <= 7; k++)
  // {
  //     kthLargest(root, k);
  // }

  // --------- 堆排序 ------------
  // int arr[] = {12, 11, 13, 5, 6, 7};
  // int n = sizeof(arr) / sizeof(arr[0]);

  // HeapSorti heap;

  // heap.headSorti(arr, n);
  // heap.printArray(arr, n);

  // ---------- 合并两个有序数组 -------
  // int arr1[] = {1, 3, 5, 7};
  // int n1 = sizeof(arr1) / sizeof(arr1[0]);

  // int arr2[] = {2, 4, 6, 8};
  // int n2 = sizeof(arr2) / sizeof(arr2[0]);

  // int arr3[n1 + n2];

  // mergeArrays(arr1, arr2, n1, n2, arr3);
  // int n3 = n1 + n2;
  // printArray(arr3, n3);

  // mergeArrays2(arr1, arr2, n1, n2);

  // --------- 移动零 ----------
  // int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  // int n = sizeof(arr) / sizeof(arr[0]);
  // pushZoresToEnd(arr, n);

  // printArray(arr, n);
  return 0;
}