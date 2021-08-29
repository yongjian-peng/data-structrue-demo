#include <iostream>
#include "TwoSum.cc"
using namespace std;

int main()
{
    TwoSum two;
    int arr[4] = {2, 2, 2, 7};
    vector<int> ao(arr, arr + 4);
    vector<int> aw;
    aw = two.twoSum1(ao, 9);

    //cout << aw << endl;

    int num = aw.size();

    cout << num << endl;

    for (int i = 0; i < num; i++)
    {
        cout << aw[i] << endl;
    }

    return 0;
}