#include <iostream>
using namespace std;

typedef struct tagSNode
{
    int value;
    tagSNode* pNext;
    tagSNode(int v): value(v), pNext(NULL) {}
}SNode;

//链表分割
void Partition(SNode* pHead, int pivotKey)
{
    //两个链表的头指针
    SNode* pLeftHead = new SNode(0);
    SNode* pRightHead = new SNode(0);

    //两个链表当前最后一个元素
    SNode* left = pLeftHead;
    SNode* right = pRightHead;
    SNode* p = pHead->pNext;
    while(p)
    {
        if(p->value < pivotKey)
        {
            left->pNext = p;
            left = p;
        }
        else
        {
            right->pNext = p;
            right = p;
        }
        p = p->pNext;
    }

    left->pNext = pRightHead->pNext;
    right->pNext = NULL;    //这句别忘！！！！
    pHead->pNext = pLeftHead->pNext;

    delete pLeftHead;
    delete pRightHead;
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
    int data[] = {11,6,7,3,5,26,7};
    int size = sizeof(data) / sizeof(int);
    //默认没有头结点。
    SNode* pHead = new SNode(0);
    for(int i = size - 1; i >= 0; i--)
    {
        SNode* p = new SNode(data[i]);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);
    Partition(pHead, 10);
    Print(pHead);
    system("pause");
    return 0;
}