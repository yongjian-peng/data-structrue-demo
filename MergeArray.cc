#include "stdc++.h"
using namespace std;

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