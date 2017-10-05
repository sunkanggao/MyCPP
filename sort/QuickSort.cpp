#include <iostream>
using namespace std;

void Print(int* a, int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void QuickSort(int* a, int left, int right)
{
    if(left < right)
    {
        int i = left;
        int j = right;
        int p = a[left];
        while(i < j)
        {
            while((i < j) && a[j] > p)
                j--;
            if(i < j)
                a[i++] = a[j];
            while((i < j) && a[i] < p)
                i++;
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = p;
        QuickSort(a, left, i - 1);
        QuickSort(a, i + 1, right);
    }
}

int main()
{
    int a[] = {3, 1, 9, 10, 4, 12, 5, 6, 7};
    int size = sizeof(a) / sizeof(int);
    Print(a, size);
    QuickSort(a, 0, size - 1);
    Print(a, size);
    system("pause");
    return 0;
}