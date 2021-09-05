#include <iostream>
#include "Default.h"
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int arr_i_targest = arr[i];
    int arr_l = arr[l];
    int arr_r = arr[r];

    for (int j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
    cout << "\n";
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        int arri = arr[i];
        int arrlargest = arr[largest];
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    int nn = n;
    cout << n << " ns_num" << endl;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " - ";
        }
        cout << "\n";
        swap(arr[0], arr[i]);
        int arr0 = arr[0];
        int arrii = arr[i];
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}