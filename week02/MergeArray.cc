#include "../stdc++.h"
using namespace std;

int runMergeArrays() {
    // ---------- 合并两个有序数组 -------
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2];

    mergeArrays(arr1, arr2, n1, n2, arr3);
    int n3 = n1 + n2;
    printArray(arr3, n3);

    mergeArrays2(arr1, arr2, n1, n2);
    return 0;
}

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    int a = i;
    int b = j;

    while (i < n1) {
        arr3[k++] = arr1[i++];
    }
    while (j < n1) {
        arr3[k++] = arr2[j++];
    }
}

void mergeArrays2(int a[], int b[], int n, int m) {
    map<int, bool> mp;
 
    for (int i = 0; i < n; i++) {
        mp[a[i]] = true;
    }

    for (int i = 0; i < m; i++) {
        mp[b[i]] = true;
    }
    for (auto i: mp) {
        cout << i.first << " ";
    }
}