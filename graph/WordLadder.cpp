#include <set>
#include <string>
#include <queue>
#include <iostream>
using namespace std;


/**
单词变换问题：给定词典和一个起点单词、一个终点单词，每次只能变换一个字母，问从起点单词能否到达终点单词？
最短多少步。起点单词和终点单词可以不在词典内。
利用BFS来求解。
**/


//搜索cur的孩子节点，存入children中
void Extend(const string& cur, vector<string>& children, const set<string>& dict,
            const string& end, set<string>& visit)
{
    string child = cur;
    children.clear();
    int i;
    char c, t;
    for(i = 0; i < (int)cur.size(); i++)
    {
        t = child[i];
        for(c = 'a'; c != 'z'; c++)
        {
            if(c == t)
                continue;
            child[i] = c;
            if(((child == end) || (dict.find(child) != dict.end())) 
                && (visit.find(child) == visit.end()))
            {
                children.push_back(child);
                visit.insert(child);
            }
        }
        child[i] = t;
    }
}

//BFS来求解该问题
int CalcLadderLength(const string& start, const string& end, const set<string>& dict)
{
    queue<string> q;
    q.push(start);
    vector<string> children;    //从当前节点可扩展得到的新节点的集合
    set<string> visit;    //已访问过的节点集合
    int step = 0;
    string cur;
    int curNumber = 1;    //当前层剩余节点数        
    int nextNumber = 0;    //下一层孩子节点数
    while(!q.empty())
    {
        cur = q.front();    //从cur开始扩展
        q.pop();
        curNumber--;
        Extend(cur, children, dict, end, visit);
        nextNumber += (int)children.size();
        if(curNumber == 0)
        {
            step++;
            curNumber = nextNumber;
            nextNumber = 0;
        }
        for(vector<string>::const_iterator it = children.begin(); it != children.end(); it++)
        {
            if(*it == end)
                return step;
            q.push(*it);
        }
    }
    return 0;
}

int main()
{
    set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    string start = "hit";
    string end = "cog";
    cout << CalcLadderLength(start, end, dict) << endl;
    system("pause");
    return 0;
}