#include <iostream>
#include "Default.h"
using namespace std;

void heapify(int arr[], int n, int i) {
    // 当前的节点 largest
    int largest = i;
    // 当前的左子节点 l = n 乘以 2 + 1
    int l = i * 2 + 1;
    // 当前的右子节点 r = n 乘以 2 + 2
    int r = i * 2 + 2;

    // 堆的特点 大顶堆 最大的值在堆顶 其子节点的值 小于 父节点

    // 判断 左子节点 是否 大于 父节点 并且 子节点下标 大于 父节点下标
    // 如果满足的话，就把 下标 赋值 largest = l
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    // 判断 右子节点 是否 大于 父节点 并且 子节点下标 大于 父节点下标
    // 如果满足的话，就把 下标 赋值 largest = r
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // 判断是否需要交换位置 largest ！= i 的话 就交换，并且 继续对比下一层
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 堆排序 1. 先把数组按照堆的结构排序 取 n 的范围 取 n 除以 2 - 1
    for (int i = n / 2 - 1; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    // 已经排好的堆 排序，是堆顶的值 和 最后一个值交换位置，然后继续 检查是否是合法的堆
    // 对比的是当前层和下一层的是否符合堆的性质：其子节点必须小于节点的值。
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}