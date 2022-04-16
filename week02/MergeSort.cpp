# include <iostream>

using namespace std;

class MergeSort {
    public:
        int run() {
            int arr[] = {12, 11, 13, 5, 6, 7};
            int n = sizeof(arr) / sizeof(arr[0]);
            mergeSort(arr, 0, n);

            cout << "Select array is \n";
            for (int i = 0; i < n; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            return 0;
            return 0;
        }

    private:
        void mergeSort(int arr[], int l, int r) {
            if (l >= r)
                return;
            int mid = (l + r) >> 1; // (l + r) / 2
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        };

        void merge(int arr[], int left, int mid, int right) {
            int lenght = right - left + 1;
            int temp[lenght];

            for (int o = 0; o < sizeof(temp);o++) {
                temp[o] = 0;
            }

            int i = left, j = mid + 1;

            for (int k = 0; k < lenght; k++) {
                if (j > right || (i <= mid && arr[i] <= arr[j])) {
                    temp[k] = arr[i++];
                } else {
                    temp[k] = arr[j++];
                }
            }

            for (int k = 0; k < lenght; k++) {
                arr[left + k] = temp[k];
            }
        }
};
