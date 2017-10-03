#include <iostream>
#include <queue>
using namespace std;

#define WATER 0
#define SOIL 1
#define OCEAN 2

/*
周围区域问题：给定一个矩阵，格点处要么是水要么是陆地，被陆地包围的水被填成陆地。
这里引入第三个概念，边缘处没有被陆地完全包围的地方叫海洋。
思路：从各边缘水格点处开始做BFS，直到遍历所有邻接水，改为海洋；
最后把水处改为陆地，海洋处改为水。
*/

void Print(vector<vector<int> >& land, int M, int N)
{
    int i, j;
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            cout << land[i][j] << ' ';
        }
        cout << endl;
    }
}

bool IsOcean(vector<vector<int> >& land, int M, int N, int i, int j)
{
    if((i < 0) || (i >= M) || (j < 0) || (j >= N))
        return false;
    return land[i][j] == WATER;    
}

void Ocean(vector<vector<int> >& land, int M, int N, int i, int j)
{
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    land[i][j] = OCEAN;
    int iDirect[] = {-1, 1, 0, 0};
    int jDirect[] = {0, 0, -1, 1};
    int iCur, jCur;
    int k;
    while(!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(k = 0; k < 4; k++)
        {
            iCur = i + iDirect[k];
            jCur = j + jDirect[k];
            if(IsOcean(land, M, N, iCur, jCur))
            {
                q.push(make_pair(iCur, jCur));
                land[iCur][jCur] = OCEAN;
            }
        }
    }
}

void FillLake(vector<vector<int> >& land, int M, int N)
{
    int i, j;

    //从边缘开始，获得海洋区域
    for(i = 0; i < M; i++)
    {
        if(land[i][0] == WATER)
            Ocean(land, M, N, i, 0);
        if(land[i][N-1] == WATER)
            Ocean(land, M, N, i, N-1);
    }
    for(j = 1; j < N-1; j++)
    {
        if(land[0][j] == WATER)
            Ocean(land, M, N, 0, j);
        if(land[M-1][j] == WATER)
            Ocean(land, M, N, M-1, j);
    }

    // 恢复海洋，填湖
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(land[i][j] == OCEAN)    //是海洋，恢复成水
                land[i][j] = WATER;
            else if(land[i][j] == WATER)    //是湖泊
                land[i][j] = SOIL;    //填湖
        }
    }
}

int main()
{
    const int M = 10;
    const int N = 15;
    //随机生成数据
    vector<vector<int>> land(M, vector<int>(N));
    int i, j;
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            land[i][j] = ((rand() % 3) == 0) ? WATER : SOIL;
        }
    }

    Print(land, M, N);
    FillLake(land, M, N);    //围湖造田
    cout << endl;
    Print(land, M, N);
    system("pause");
    return 0;
}

