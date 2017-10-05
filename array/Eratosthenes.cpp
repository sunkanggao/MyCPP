#include <iostream>
#include <list>
#include <fstream>
using namespace std;

/*
用Eratosthenes筛法打印1000000内的所有素数。
*/

void Eratosthenes(bool* a, int n)
{
    a[1] = false;    //a[0]不用
    int i;
    for(i = 2; i <= n; i++)    //筛法，默认是素数
        a[i] = true;
    int p = 2;    //第一个筛孔
    int j = p*p;
    while(j <= n)
    {
        while(j <= n)
        {
            a[j] = false;
            j += p;
        }
        p++;
        while(!a[p])    //如果不是素数，就寻找下一个素数
            p++;
        j= p*p;
    }
}

int main()
{
    int N = 1000000;
    bool* num = new bool[N+1];
    Eratosthenes(num, N);
    list<int> p;
    for(int i = 1; i <= N; i++)
    {
        if(num[i])
            p.push_back(i);
    }
    ofstream inFile;
    inFile.open("Prime.txt", ios::trunc);
    cout << "The number of Prime is:\n";
    cout << p.size() << endl;
    for(list<int>::iterator it = p.begin(); it != p.end(); it++)
    {
        // cout << *it << " ";
        inFile << *it << " ";
    }
    cout << endl;
    system("pause");
    inFile.close();
    return 0;
}