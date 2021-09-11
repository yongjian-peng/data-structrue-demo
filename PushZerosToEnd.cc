#include <iostream>
using namespace std;

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