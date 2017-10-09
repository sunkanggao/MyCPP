#include <iostream>
using namespace std;

typedef struct tagSNode
{
    int value;
    tagSNode* pNext;

    tagSNode(int v) : value(v), pNext(NULL) {} 
}SNode;

//链表加和
SNode* Add(SNode* pHead1, SNode* pHead2)
{
    SNode* pSum = new SNode(0);    //默认有头结点
    SNode* pTail = pSum;    //新节点插入到pTail后面
    SNode* p1 = pHead1->pNext;
    SNode* p2 = pHead2->pNext;
    SNode* pCur;
    int carry = 0;
    int value;
    while(p1 && p2)
    {
        value = p1->value + p2->value + carry;
        carry = value / 10;
        value %= 10;
        pCur = new SNode(value);
        pTail->pNext = pCur;
        pTail = pCur;

        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    //处理较长的链
    SNode* p = p1 ? p1 : p2;
    while(p)
    {
        value = p->value + carry;
        carry = value / 10;
        value %= 10;
        pCur = new SNode(value);
        pTail->pNext = pCur;
        pTail = pCur;
        p = p->pNext;
    }
    //处理可能存在的进位
    if(carry != 0)
    {
        pCur = new SNode(carry);
        pTail->pNext = pCur;
    }
    return pSum;
}

void Print(SNode* pHead)
{
    //默认带头结点
    SNode* p = pHead->pNext;
    while(p)
    {
        cout << p->value;
        p = p->pNext;
        if(p) cout << "->";
    }
    cout << endl;
}


int main()
{
    int data1[] = {1,8,8,9,5,6,7};
    int data2[] = {9,2,4,8,3,1,3};
    int size = sizeof(data1) / sizeof(int);
    SNode* pHead1 = new SNode(0);
    SNode* pHead2 = new SNode(0);
    for(int i = size - 1; i >= 0; i--)
    {
        SNode* p = new SNode(data1[i]);
        SNode* q = new SNode(data2[i]);
        p->pNext = pHead1->pNext;
        pHead1->pNext = p;
        q->pNext = pHead2->pNext;
        pHead2->pNext = q;

    }
    Print(pHead1);
    Print(pHead2);
    SNode* pSum = Add(pHead1, pHead2);
    Print(pSum);
    system("pause");
    return 0;
}