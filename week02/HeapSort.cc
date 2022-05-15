#include <iostream>

#include "Heapify.cc"

using namespace std;

class HeapSort
{
    public:

        int main() {
            int arr[] = { 5, 20, 6 };

            int n = sizeof(arr) / sizeof(arr[0]);

            heapSort(arr, n);

            cout << "Sorted array is \n";
            printArray(arr, n);
            return 0;
        }

    private:
        void heapSort(int arr[], int n)
        {
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(arr, n, i);
            }

            for (int i = n - 1; i > 0; i--) {
                swap(arr[i], arr[0]);
                heapify(arr, i, 0);
            }
        };
        void heapify(int arr[], int n, int i)
        {
            int largest = i;
            int l = i * 2 + 1;
            int r = i * 2 + 2;

            if (l < n && arr[l] > arr[largest]) {
                largest = l;
            }
            if (r < n && arr[r] > arr[largest]) {
                largest = r;
            }

            if (largest != i) {
                swap(arr[largest], arr[i]);
                heapify(arr, n, largest);
            }
        }
};