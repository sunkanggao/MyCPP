#include <iostream>
#include <algorithm>
using namespace std;

/*
堆是一棵完全二叉树，可以用数组存储。
索引为k的孩子结点的索引是2k+1，2k+2（如果存在），父节点索引为(k+1)/2-1。
*/

void Print(int* a, int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}


//调整以n为顶的堆为大顶堆
void HeapAdjust(int* a, int k, int size)
{
    int child = 2 * k + 1;    //左孩子
    int t;
    while(child < size)
    {
        if((child + 1 < size) && (a[child + 1] > a[child]))    //找大孩子
            child++;
        if(a[child] < a[k])    //孩子比父亲小，说明调整完毕。
            break;
        t = a[child];
        a[child] = a[k];
        a[k] = t;

        k = child;
        child = 2 * k + 1;
    }
}

void HeapSort(int* a, int size)    //从数组中找前k大的数，若k=size，则为堆排序。
{
    for(int i = size / 2 - 1; i >= 0; i--)    //初始化：将a[0..n-1]初始化为最大堆，从size/2 - 1位开始往前调整。
        HeapAdjust(a, i, size);
    int t;
    while(size > 0)    //第i趟排序：将堆顶记录a[0]和a[n-i]交换，然后将a[0...n-i-1]调整为堆（即，重建最大堆）
    {
        t = a[size - 1];    
        a[size - 1] = a[0];
        a[0] = t;
        size--;
        HeapAdjust(a, 0, size);
    }
}

int main()
{
    const int size = 10;
    int a[size];
    for(int i = 0; i < size; i++)
        a[i] = i;
    random_shuffle(a, a + size);
    Print(a, size);
    HeapSort(a, size);
    Print(a, size);
    system("pause");
    return 0;
}