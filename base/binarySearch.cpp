#include <iostream>
using namespace std;

#define MAX_SIZE 102

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

int main()
{
    int a[MAX_SIZE];
    int i, len, x, p;
    cin >> len;
    for(i=0; i<len; i++)
        cin >> a[i];
    cin >> x;
    p = BinarySearch(a, x, len);
    if(p == -1)
        cout << "该数不存在！" << endl;
    else
        cout << p+1 << endl;
    system("pause");
    return 0;
}