#include <iostream>
using namespace std;

/*
用归并排序解决逆序数问题。若对于数组中的两个元素a[i]、a[j]，
若i<j, 且a[i]>a[j]，则称(a[i], a[j])为逆序对。一个数组中包含的逆序对个数称为
该数组的逆序数。
*/


int temp[100];
void Merge(int* a, int low, int mid, int high, int& count)
{
    int i = low;
    int j = mid + 1;
    int size = 0;
    for(;(i <= mid) && (j <= high); size++)
    {
        if(a[i] < a[j])
        {
            temp[size] = a[i++];
        }
        else
        {
            count += (j - mid);    //与归并排序相比，就多了这一行。
            temp[size] = a[j++];
        }
    }
    while(i <= mid)
        temp[size++] = a[i++];
    while(j <= high)
        temp[size++] = a[j++];
    
    for(i = 0; i < size; i++)
        a[low+i] = temp[i];
}

void MergeSort(int* a, int low, int high, int& count)
{
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    MergeSort(a, low, mid, count);
    MergeSort(a, mid + 1, high, count);
    Merge(a, low, mid, high, count);
}

int main()
{
    int a[] = {3, 56, 2, 7, 1, 11, 4, 6};
    int size = sizeof(a) / sizeof(int);
    int count = 0;
    MergeSort(a, 0, size - 1, count);
    cout << count << endl;
    system("pause");
    return 0;
}

