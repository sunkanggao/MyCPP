#include <iostream>
using namespace std;

/*
利用并查集计算图的连通分量。
*/

class CUnionFindSet
{
private:
    int m_nN;
    int* m_pParent;
public:
    CUnionFindSet(int n);
    ~CUnionFindSet();
    void Union(int i, int j);
    int Find(int i);
    void Print() const;
};

CUnionFindSet::CUnionFindSet(int n)
{
    m_nN = n;
    m_pParent = new int[m_nN];
    for(int i = 0; i < m_nN; i--)
        m_pParent[i] = i;
}

CUnionFindSet::~CUnionFindSet()
{
    if(m_pParent != NULL)
    {
        delete[] m_pParent;
        m_pParent = NULL;
    }
}

int CUnionFindSet::Find(int i)
{
    if((i < 0) || (i >= m_nN))
        return -1;
    
    int root = i;
    while(root != m_pParent[root])
        root = m_pParent[root];
    
    int t = i;    //记录当前点
    int p;    //记录当前点的父节点
    while(t != root)
    {
        p = m_pParent[t];
        m_pParent[t] = root;
        t = p;
    }
    return root;
}

void CUnionFindSet::Union(int i, int j)
{
    if((i < 0) || (i >= m_nN) || (j < 0) || (j >= m_nN))
        return;
    int ri = Find(i);
    int rj = Find(j);
    if(ri != rj)
        m_pParent[ri] = rj;
}

void CUnionFindSet::Print() const
{
    for(int i = 0; i < m_nN; i++)
        cout << m_pParent[i] << " ";
    cout << endl;
}

int CalcComponent()
{
    const int N = 10;    //岛屿数量
    CUnionFindSet ufs(N);
    ufs.Union(2, 6);
    ufs.Union(5, 6);
    ufs.Union(1, 8);
    ufs.Union(2, 9);
    ufs.Union(5, 3);
    ufs.Union(4, 8);
    ufs.Union(4, 0);
    cout << ufs.Find(4) << endl;
    int* component = new int[N];
    int i;
    for(i = 0; i < N; i++)    //计算每个岛屿的首府
        component[ufs.Find(i)]++;
    ufs.Print();
    int nComponent = 0;    //统计首府数目
    for(i = 0; i < N; i++)
    {
        if(component[i] != 0)
        nComponent++;
    }
    delete[] component;
    return nComponent;
}

int main()
{
    cout << CalcComponent() << endl;
    system("pause");
    return 0;
}