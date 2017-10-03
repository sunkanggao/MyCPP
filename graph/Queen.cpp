#include <iostream>
#include <vector>
using namespace std;

/*
用DFS解决8皇后问题。
显然任意一行有且仅有一个皇后，用一个path数组表示第i行的皇后位于哪一列。
DFS：将第i个皇后放置在第j列上，如果当前位置与其他皇后相互攻击，则剪枝掉该节点。
分析对角线：最对角线，i-j为定值；次对角线，i+j为定值；
分析列：任意两皇后不能位于同一列。（行已保证）
*/

class CQueen
{
private:
    int m_nQueen;
    vector<bool> m_Colomn;   //path已经占据的列
    vector<bool> m_MainDiagonal;    //path已经占据的主对角线
    vector<bool> m_MinorDiagonal;    //path已经占据的次对角线
    vector<vector<int> > m_Answer;    //最终解集合

public:
    CQueen(int N) : m_nQueen(N)
    {
        m_Colomn.resize(N, false);
        m_MainDiagonal.resize(2*N-1, false);
        m_MinorDiagonal.resize(2*N-1, false);
    }

    void Queen()
    {
        int* path = new int[m_nQueen];
        CalcNQueen(path, 0);
        delete[] path;
    }

private:
    void CalcNQueen(int* path, int row)
    {
        if(row == m_nQueen)
        {
            m_Answer.push_back(vector<int>(path, path + m_nQueen));
            return;
        }
        for(int col = 0; col < m_nQueen; col++)
        {
            if(CanLay(row, col))
            {
                path[row] = col;
                m_Colomn[col] = true;
                m_MinorDiagonal[row + col] = true;
                m_MainDiagonal[m_nQueen - 1 + row - col] = true;
                CalcNQueen(path, row + 1);
        
                //回溯
                m_Colomn[col] = false;
                m_MinorDiagonal[col + row] = false;
                m_MainDiagonal[m_nQueen - 1 + row - col] = false;
            }
        }
    }

    bool CanLay(int row, int col) const
    {
        return !m_Colomn[col] && !m_MinorDiagonal[row + col] && !m_MainDiagonal[m_nQueen - 1 + row - col];
    }

public:
    void Print() const
    {
        cout << "The result is " << (int)m_Answer.size() << endl;
        for(vector<vector<int> >::const_iterator it = m_Answer.begin(); it != m_Answer.end(); it++)
            PrintOne(*it);
    }

    void PrintOne(const vector<int>& v) const
    {
        for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
};

int main()
{
    CQueen queen(8);
    queen.Queen();
    queen.Print();
    system("pause");
    return 0;
}