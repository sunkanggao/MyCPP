#include <iostream>
using namespace std;

/*
给定数组和定值sum，找到数组中数组中的两个数，使得它们的和为sum。
*/

void TwoSum(const int* a, int size, int sum)
{
    int low = 0;
    int high = size - 1;
    while(low < high)
    {
        int s = a[low] + a[high];
        if(s < sum)
            low++;
        else if(s > sum)
            high--;
        else
        {
            cout << a[low] << " " << a[high] << endl;
            low++;
            high--;
        }
    }
}

int main()
{
    int a[] = {0, 3, 7, 9, 11, 14, 16, 17};
    int size = sizeof(a) / sizeof(int);
    // sort(a, a + size);    //若原数组无序，先排序
    TwoSum(a, size, 20);
    system("pause");
    return 0;
}