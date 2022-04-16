#include <iostream>

using namespace std;

class QuickSort
{
    // 快速排序 
    public:
        int run() {
            int arr[] = {12, 11, 13, 5, 6, 7};
            int n = sizeof(arr) / sizeof(arr[0]);

            quickSort(arr, 0, n);

            
            cout << "QuickSort array is \n";
            for (int i = 0; i < n; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            return 0;
        }

    private:
        void quickSort(int arr[], int l, int r) {
            if (l == r)
                return;
            int pivot = partition(arr, l, r);
            quickSort(arr, l, pivot);
            quickSort(arr, pivot + 1, r);
        };
        int partition(int arr[], int l, int r) {
            int pivot = l + (rand() % (r - l )) + 1;
            int pivotVal = arr[pivot];
            while (l <= r) {
                while (arr[l] < pivotVal)
                    l++;
                while (arr[r] > pivotVal)
                    r--;
                if (l <= r) {
                    int temp = arr[l];
                    arr[l] = arr[r];
                    arr[r] = temp;
                    l++;
                    r--;
                }
            }
            return r;
        }
};
