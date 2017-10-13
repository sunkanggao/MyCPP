#include <iostream>
using namespace std;

void ReverseString(char* s, int from, int to)
{
    while(from < to)
    {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void LeftRotateString(char* s, int size, int m)
{
    //循环左移m位。
    m %= size;
    ReverseString(s, 0, m - 1);    //前m位翻转
    ReverseString(s, m, size - 1);    //后size - m位翻转
    ReverseString(s, 0, size - 1);    //整体翻转
}

void Print(char* s, int size)
{
    for(int i = 0; i < size; i++)
        cout << s[i];
    cout << endl;
}

int main()
{
    char s[] = "abcde";
    int size = sizeof(s) / sizeof(char) - 1;    //减去末尾的结束字符
    Print(s, size);
    LeftRotateString(s, size, 3);
    Print(s, size);
    system("pause");
    return 0;
}