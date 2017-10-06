#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/*
杨氏矩阵的增删改查。默认杨氏矩阵的每一行、每一列都是递增的。
*/

#define INFINITY 100000
#define ROW 5
#define COL 4
typedef vector<vector<int> > mat; 

void Print(mat &a)
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
            cout << std::left << setw(8) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool Insert(mat &a, int x)
{
    int row = ROW - 1;
    int col = COL - 1;
    if(a[row][col] < INFINITY)
        return false;
    a[row][col] = x;
    int r = row;
    int c = col;
    while((row >= 0) || (col >= 0))
    {
        if((row >= 1) && (a[row - 1][col] > a[r][c]))
        {
            r = row - 1;
            c = col;
        }
        if((col >= 1) && (a[row][col - 1] > a[r][c]))
        {
            r = row;
            c = col - 1;
        }
        if((row == r) && (col == c))
            break;
        swap(a[row][col], a[r][c]);
        row = r;
        col = c;
    }
    return true;
}

//从右上角或左下角开始寻找。
bool Find(mat &a, int x, int &row, int &col)
{
    row = 0;
    col = COL - 1;
    while((row < ROW) && (col >= 0))
    {
        if(a[row][col] == x)
            return true;
        if(a[row][col] > x)
            col--;
        else
            row++;
    }
    return false;
}

//删除杨氏矩阵中某一个值，即把该值改为INFINITY，然后再寻找其相邻下方和右方较小的一个数和它交换。
void Delete(mat &a, int row, int col)
{
    int r = row;
    int c = col;
    while((row < ROW) && (col < COL))
    {
        if(a[row][col] == INFINITY)
            break;
        if(row + 1 < ROW)
        {
            r = row + 1;
            c = col;
        }
        if((col + 1 < COL) && (a[row][col + 1] < a[r][c]))
        {
            r = row;
            c = col + 1;
        }
        if((r == row) && (c == col))
            break;
        a[row][col] = a[r][c];
        row = r;
        col = c;
    }
    a[ROW - 1][COL - 1] = INFINITY;    //保护作用
}


int main()
{
    mat cyoung(ROW, vector<int>(COL, INFINITY));
    int a[] = {50, 20, 15, 3, 25, 70, 40, 18, 55, 10};
    int size = sizeof(a) / sizeof(int);
    for(int i = 0; i < size; i++)
    {
        Insert(cyoung, a[i]);
        Print(cyoung);
    }
    int x, y, z = 15;
    if(Find(cyoung, z, x, y))
        cout << z << " is at (" << x << ", " << y << ")!\n" << endl;
    else
        cout << z << " is not in mat!\n" << endl;
    Delete(cyoung, 1, 1);
    Print(cyoung);
    system("pause");
    return 0;
}