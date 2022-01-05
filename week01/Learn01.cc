#include "./Trap.cc"
#include "MaxFreq.cc"
#include "LargestRectangleArea2.cc"
#include "TreeDiameter.cc"
// using namespace std;

#include "NumberofCattle.cc"

#include "NeighborSearch.cc"

#include "LargestRectangleArea.cc"

#include "LargestRectangleArea3.cc"

#include "Calculate.cc"

#include "MergeTwoArray.cc"

#include "RemoveDuplicates.cc"

#include "../stdc++.h"

class Learn01 {
    public:
        int main() {
            // 删除数组中 重复的项
            // RemoveDuplicates removeDuplicates;
            // int r = removeDuplicates.main();
            // 合并两个数组
            // MergeTwoArray mergeTwoArray;
            // mergeTwoArray.main();
            
            // 邻值查找
            // NeighborSearch NeighborSearch;
            // NeighborSearch.neighborSearch();

            // 横条解题 单调栈
            // Trap trap;
            // LargestRectangleArea2 lra2;
            // trap.main();

            // LargestRectangleArea2 lra2;
            // lra2.main();

            // 给出一串字符串，要求找出字符串内连续出现次数最高的字母，
            // 如果存在多个字母并列出现次数最高，则需要把全部都列举出来
            // MaxFreq mf;
            // mf.main();

            // 树的直径
            // TreeDiameter td;
            // td.main();

            // 初始只有一头牛。牛只有6年的生命(第0年出生，第6年死去)，牛第3年和第5年会生小牛。问：初始只有一只牛，求第n年牛的个数
            NumberofCattle nc;
            nc.main();

            // ----------- 柱状图中最大矩形 ----------
            // LargestRectangleArea lra;
            // lra.main();

            // LargestRectangleArea3 Lra3;
            // Lra3.main();

            // ----------- 计算器 ------------
            Calculate cal;
            cal.main();

            return 0;
        }

        int lenmap() {
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
            // map.erase(1010);
            // Pair<int, string> *it = map.find(1010);
            // if (it == nullptr)
            // {
            //   cout << "not find" << endl;
            // }
            // else
            // {
            //   cout << it->first << endl;
            // }
            return 0;
        }


        int learn_priority_queue() {
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
            return 0;
        }

};