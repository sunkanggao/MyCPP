#include <iostream>
using namespace std;

//链表翻转（维持p,q,r三个指针，r记录下一个要访问的节点，每次都把p指向q）

typedef struct tagSNode
{
    int value;
    tagSNode* pNext;
    tagSNode(int v): value(v), pNext(NULL) {}
}SNode;

SNode* Reverse(SNode* pHead)
{
    //不带头结点
    if((pHead == NULL) || (pHead->pNext == NULL)) return pHead;
    SNode* p;
    SNode* q;
    SNode* r;
    p = pHead;
    q = pHead->pNext;
    pHead->pNext = NULL;
    while(q)
    {
        r = q->pNext;    //先保留下一个step要处理的指针
        q->pNext = p;    //然后p，q交替工作进行反向。
        p = q;
        q = r;
    }
    pHead = p;
    return pHead;
}

SNode* Reverse2(SNode* pHead)
{
    //带有头结点
    if((pHead->pNext == NULL) || (pHead->pNext->pNext == NULL)) return pHead;
    SNode* p = pHead->pNext;
    SNode* q = p->pNext;
    SNode* r;
    p->pNext = NULL;
    while(q)
    {
        r = q->pNext;
        q->pNext = p;
        p = q;
        q = r;
    }
    pHead->pNext = p;
    return pHead;
}

void Reverse3(SNode* pHead, int from, int to)
{
    //链表部分翻转
    SNode* pCur = pHead->pNext;
    int i;
    //空转from-1次
    for(i = 0; i < from - 1; i++)
    {
        pHead = pCur;
        pCur = pCur->pNext;
    }
    SNode* pPre = pCur;
    pCur = pCur->pNext;
    SNode* pNext;
    to--;
    for(; i < to; i++)
    {
        pNext = pCur->pNext;
        pCur->pNext = pHead->pNext;
        pHead->pNext = pCur;
        pPre->pNext = pNext;
        pCur = pNext;
    }

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
    int data[] = {1,2,3,4,5,6,7};
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
    // pHead = Reverse2(pHead);
    Reverse3(pHead, 2, 5);
    Print(pHead);
    system("pause");
    return 0;
}
