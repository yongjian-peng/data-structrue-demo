#include "MapDemo.cc"

#include "NumberOfSubarrays.cc"
#include "TwoSum.cc"

#include "Reverse.cc"

#include "ReverseBetween.cc"

#include "KthLargest.cc"

#include "HeapSort.cc"

#include "MergeArray.cc"

#include "PushZerosToEnd.cc"

#include "MoveAnt.cpp"

#include "FindLAC.cc"

#include "SelectSort.cpp"

#include "InsertSort.cpp"

#include "MergeSort.cpp"

#include "QuickSort.cpp"

class Learn02
{
public:
    int main()
    {
        // --------- 统计优美子数组 ----------
        // NumberOfSubarrays ns;
        // ns.main();

        // 两数之和
        // TwoSum two;
        // two.main();

        // ----------------- 链表 k个一组反转链表 ------------------
        // Reverse re;
        // re.main();

        //  ---------------- 反转链表 输入 左 右 返回区间内反转 ------------------
        // ReverseBetween reb;
        // reb.main();

        // ------ 堆排序 ---------
        HeapSort heapSort;
        heapSort.main();

        // -------- 动态查找 第 k 大元素 ----------
        // runKthLargest();

        // ---------- 合并两个有序数组 -------
        // runMergeArrays();

        // --------- 移动零 ----------
        // runPushZoresToEnd();

        // 移动蚂蚁
        // MoveAnt moveAnt;
        // moveAnt.main();

        // 选择排序
        // SelectSort selectSort;
        // selectSort.run();

        // 插入排序
        // InsertSort insertSort;
        // insertSort.run();

        // 合并排序
        // MergeSort mergeSort;
        // mergeSort.run();

        // 快速排序
        // QuickSort quickSort;
        // quickSort.run();

        return 0;
    }
};