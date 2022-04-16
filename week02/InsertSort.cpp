#include <iostream>

using namespace std;

class InsertSort
{
    // 插入排序
    // 循环选择最小的
    public:
        int run() {
            int arr[] = {12, 11, 13, 5, 6, 7};
            int n = sizeof(arr) / sizeof(arr[0]);
            insertSort(arr, n);

            cout << "Insert Sort is \n";
            for (int i = 0; i < n; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            return 0;
        };

    private:
        void insertSort(int arr[], int len) {
            
            for (int i = 1; i < len ; ++i) {
                int temp = arr[i];

                for (int j = i - 1; j >= 0; --j) {
                    if (arr[j] < temp) {
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    } else
                        break;
                }
            }
        }
};
