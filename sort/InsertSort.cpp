#include <iostream>
using namespace std;

/*
1. 从第一个元素开始，该元素可以认为已经被排序
2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
4. 重复步骤 3，直到找到已排序的元素小于或者等于新元素的位置
5. 将新元素插入到该位置后
6. 重复步骤 2~5
*/


void Print(int* a, int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void InsertSort(int* a, int size)
{
    int inserter, index, k;
    for(k = 1; k < size; k++)
    {
        inserter = a[k];
        index = k - 1;
        while(index >= 0 && inserter < a[index])    //这里可以换成二分查找优化
        {
            a[index + 1] = a[index];
            index--;
        }
        a[index + 1] = inserter;
    }
}

int main()
{   
    int a[] = {5, 6, 2, 2, 1, 7, 8, 6};
    int size = sizeof(a) / sizeof(int);
    Print(a, size);
    InsertSort(a, size);
    Print(a, size);
    system("pause");
    return 0;
}