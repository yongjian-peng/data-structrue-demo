#include <iostream>
#include "Default.h"
using namespace std;


class HeapSorti
{
    public:
        void headSortUtil(int arr[], int n, int i) {
            // 定义 l r largest
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            // 如果 l < n 并且 arr[l] < arr[largest]
            if (l < n && arr[l] > arr[largest]) {
                largest = l;
            }
            if (r < n && arr[r] > arr[largest]) {
                largest = r;
            }
            // 如果 largest 和 i 不等 则 替换 arr[i] arr[largest] 位置
            if (largest != i) {
                swap(arr[i], arr[largest]);
                headSortUtil(arr, n, largest);
            }
        }
    public:
        void headSorti(int arr[], int n) {
            // 构造堆 大顶堆 升序排序
            for (int i = n / 2 - 1; i >= 0; i--) {
                headSortUtil(arr, n, i);
            }
            // 交换堆的最后一个元素和 堆顶的位置
            for (int i = n - 1; i > 0; i--) {
                swap(arr[0], arr[i]);
                headSortUtil(arr, i, 0);
            }
        }
    public:
        void printArray(int arr[], int n)
        {
            for (int i = 0; i < n; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
};