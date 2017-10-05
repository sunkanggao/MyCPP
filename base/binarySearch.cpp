#include <iostream>
using namespace std;

#define MAX_SIZE 102

//递归实现
template<class T>
int BinarySearch(T a[], const T& x, int n)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int middle = (left + right) / 2;
        if(a[middle] == x)
            return middle;
        else if(a[middle] > x)
            right = middle - 1;
        else if(a[middle] < x)
            left = middle + 1;
    }
    return -1;
}

//非递归实现
template<class T>
int BinarySearch2(T a[], const T& x, int left, int right)
{
    if(left > right)
        return -1;
    int mid = (left + right) / 2;
    if(a[mid] == x)
        return mid;
    else if(a[mid] > x)
        BinarySearch2(a, x, left, mid - 1);
    else if(a[mid] < x)
        BinarySearch2(a, x, mid + 1, right);
}

int main()
{
    int a[MAX_SIZE];
    int i, len, x, p;
    cin >> len;
    for(i=0; i<len; i++)
        cin >> a[i];
    cin >> x;
    p = BinarySearch(a, x, len);
    // p = BinarySearch2(a, x, 0, len - 1);
    if(p == -1)
        cout << "该数不存在！" << endl;
    else
        cout << p+1 << endl;
    system("pause");
    return 0;
}