#include <iostream>
using namespace std;

void Print(int* a, int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

int temp[100];
void Merge(int*a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    while((i <= mid) && (j <= high))
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];
    while(j <= high)
        temp[k++] = a[j++];

    for(i = 0; i < k; i++)
        a[low + i] = temp[i];    
}

void MergeSort(int* a, int low, int high)
{
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid+1, high);
    Merge(a, low, mid, high);
}

int main()
{
    int a[] = {4, 2, 4, 65, 7, 8, 64, 3};
    int size = sizeof(a) / sizeof(int);
    Print(a, size);
    MergeSort(a, 0 , size - 1);
    Print(a, size);
    system("pause");
    return 0;
}