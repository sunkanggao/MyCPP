#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/*
用DFS解决百数问题。在1，2，3，4，5，6，7，8插入+、-、空，是得最后计算结果为100.
输出所有可行的运算符方式。
*/

void Print(int index, const int* a, const vector<pair<int, char> >& op, int size)
{
    cout << index << ":  ";
    vector<pair<int, char> >::const_iterator o = op.begin();
    for(int i = 0; i < size; i++)
    {
        cout << a[i];
        if(i == size - 1)
            break;
        if((o != op.end()) && (o->first == i))
        {
            cout << " " << o->second << " ";
            o++;
        }
    }
    cout << endl;
}

bool LastOperator(vector<pair<int, char> >& op, int size)
{
    if(op.empty())
        return true;
    return op.back().second == '+';
}

//考察第cur个空位，当前表达式的值是n，当前表达式最后一个数是last，操作符放置于op
bool Calc(const int* a, int size, int cur, int n, int last, 
    vector<pair<int, char> >& op, int sum, int& count)
{
    if(cur == size - 1)    //递归结束
    {
        last = 10 * last + a[size - 1];
        if((LastOperator(op, cur - 1) ? (n + last) : (n - last)) == sum)    //找到解
        {
            count++;
            Print(count, a, op, size);
            return true;
        }
        return false;
    }
    last = 10 * last + a[cur];
    Calc(a, size, cur + 1, n, last, op, sum, count);    //空
    bool bAdd = LastOperator(op, cur - 1);
    op.push_back(make_pair(cur, '+'));    //'+'
    Calc(a, size, cur + 1, bAdd ? n + last : n - last, 0, op, sum, count);
    op.back().second = '-';    //'-'
    Calc(a, size, cur + 1, bAdd ? n + last : n - last, 0, op, sum, count);
    op.pop_back();
    return count != 0;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(a) / sizeof(int);
    vector<pair<int, char> > op;
    int count = 0;
    Calc(a, size, 0, 0, 0, op, 100, count);
    system("pause");
    return 0;
}