#include <iostream>
using namespace std;

int runPushZoresToEnd() {
    // --------- 移动零 ----------
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // pushZoresToEnd(arr, n);

    // printArray(arr, n);
    return 0;
}

void pushZoresToEnd(int arr[], int n) {
    // 把需要的押入数组中

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    // 后面空出的补充 0
    while (count < n) {
        arr[count++] = 0;
    }
}