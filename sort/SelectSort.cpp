#include <iostream>
using namespace std;

/*
在数组array[begin:end]中先选定一个数array[begin]，再在余下的数中遍历，
如果找到比array[begin]小的数，那么就将这个数作为选定的数，再往下遍历，如果还有更小的，
那么继续换掉下标，直到找到最小的为止，然后将这个最小和数组第一个数array[0]交换，
再在余下的数中找到最小的放在第二个位置array[1]。
*/

void Print(int* a, int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl; 
}

void SelectSort(int* a, int size)
{
    for(int i = 0; i < size; i++)
    {
        int index = i;
        for(int j = i + 1; j < size; j++)
        {
            if(a[j] < a[index])
                index = j;
        }
        if(index != i)
        {
            int t = a[i];
            a[i] = a[index];
            a[index] = t; 
        }
    }
}

int main()
{
    int a[] = {5, 6, 2, 2, 1, 7, 8, 6};;
    int size = sizeof(a) / sizeof(int);
    Print(a, size);
    SelectSort(a, size);
    Print(a, size);
    system("pause");
    return 0;
}