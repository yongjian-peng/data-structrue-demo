#include <iostream>

using namespace std;

class SelectSort
{
    // 选择排序 
    // 循环选择最小的
    public:
        int run() {
            int arr[] = {12, 11, 13, 5, 6, 7};
            int n = sizeof(arr) / sizeof(arr[0]);
            selectSort(arr, n);

            cout << "Select array is \n";
            for (int i = 0; i < n; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            return 0;
        };

    private:
        void selectSort(int arr[], int n) {
            int min, len = n;
            for (int i = 0; i < len - 1; i++) {
                min = i;
                for (int j = i + 1; j < len; ++j) {
                    if (arr[j] < arr[min]) {
                            min = j;
                        }
                }
                if (i != min) {
                    swap(arr[i], arr[min]);
                }
            }
        }
};
