#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
素和阶数：有些正整数可以写成两个素数的和，如8=5+3；
一个正整数可以被拆分成两个素数和的数目为"素和阶数"。
请计算100万以内哪个数的素和阶数最大。
*/

int TwoSum(int* a, int sum, int size)
{
    int low = 0;
    int high = size - 1;
    int count = 0;
    while(low < high)
    {
        int s = a[low] + a[high];
        if(s > sum)
            high--;
        else if(s < sum)
            low++;
        else
        {
            count++;
            high--;
            low++;
        }
    }
    return count;
}

//二分查找
int Find(int* a, int x, int left, int right)
{
    if(left > right)
        return left;
    int mid = (left + right) / 2;
    if(a[mid] == x)
        return mid;
    else if(a[mid] > x)
        Find(a, x, left, mid - 1);
    else if(a[mid] < x)
        Find(a, x, mid + 1, right);
}

int main()
{
    ifstream iFile;
    iFile.open("E:\\project\\algoCPP\\Prime.txt");    //读入素数
    vector<int> a;
    int i;
    while(iFile >> i)
        a.push_back(i);
    int* p = &a.front();    //100万以内的所有素数
    int size = (int)a.size();
    int j;
    int m = 0;    //素和阶数
    int f = 0;    //哪个整数得到最大的素和阶数
    for(i = 0; i < 1000000; i++)
    {
        j = Find(p, i, 0, size - 1);    //获取素数表中大于当前值i的最小索引
        j = TwoSum(p, i, j);    //获得当前数i的素和阶数
        if(m < j)
        {
            m = j;
            f = i;
        }
    }
    cout << f << " " << m << endl;    //990990: 15594
    system("pause");
    return 0;
}