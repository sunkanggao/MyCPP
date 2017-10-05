#include <iostream>
using namespace std;

/*
原理：临近的数字两两进行比较，按照从小到大或者从大到小的顺序进行交换，
这样一趟过去后，最大或最小的数字被交换到了最后一位，然后再从头开始进行两两比较交换，
直到倒数第二位时结束，依此类推。
*/

void Print(int* a, int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void BubbleSort(int* a, int size)
{
    int i, j;
    int temp;
    bool bBubble;
    for(i = 0; i < size - 1; i++)
    {
        bBubble = false;
        for(j = 0; j < size - 1 - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                bBubble = true;
            }
        }
        if(!bBubble)
            break;
    }
}

int main()
{
    int a[] = {5, 4, 1, 2, 9, 8, 6, 4};
    int size = sizeof(a) / sizeof(int);
    Print(a, size);
    BubbleSort(a, size);
    Print(a, size);
    system("pause");
    return 0;

}