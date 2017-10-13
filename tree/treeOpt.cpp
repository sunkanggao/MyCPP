#include <iostream>
#include <queue>
using namespace std;

typedef struct BinNode{
    int data;
    BinNode* left;
    BinNode* right;
    BinNode(int v) : data(v), left(NULL), right(NULL){}
}BinNode;

/*
如果二叉树为空，则二叉树的深度为0；
如果二叉树不为空，二叉树的深度=MAX(左子树深度，右子树深度)+1
*/
int TreeHight(BinNode* root)
{
    int h, left, right;
    if(!root)
        return 0;
    left = TreeHight(root->left);
    right = TreeHight(root->right);
    h = (left > right? left : right) + 1;
    return h;
}

/*
如果二叉树为空，节点的个数为0；
如果二叉树不为空，二叉树节点的个数=左子树节点个数+右子树节点个数+1；
*/
int GetNodeCount(BinNode* root)
{
    int count = 0, leftNum, rightNum;
    if(!root)
        return 0;
    left = GetNodeCount(root->left);
    right = GetNodeCount(root->right);
    count = left + right + 1;
    return count;
}

/*
深度优先搜索（前序，中序，后序）
*/
void preOrder(BinNode* root)
{
    if(!root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

/*
广度优先搜索（层序遍历）
*/
void LevelTraverse(BinNode* root)
{
    if(!root)
        return;
    queue<BinNode*> q;
    q.push(root);
    while(!q.empty())
    {
        BinNode* pNode = q.front();
        q.pop();
        cout << pNode->data << " "
        if(pNode->left != NULL)
            p.push(pNode->left);
        if(pNode->right != NULL)
            q.push(pNode->right);
    }
}

/*
二叉树翻转
*/
void ReverseTree(BinNode* root)
{
    if(!root)
        return;
    BinNode* p = root->left;
    root->left = root->right;
    root->right = p;
    ReverseTree(root->left);
    ReverseTree(root->right);
}