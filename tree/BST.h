#include <iostream>
#include <new>
#include <iomanip>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename T>
class BST
{
public:
    BST();
    bool empty() const;
    bool search(const T & item) const;
    void insert(const T & item);
    void remove(const T & item);
    void inorder(ostream & out) const;
    void graph(ostream & out) const;    // 图形化输出树

private:
    class BinNode
    {
    public:
        T data;
        BinNode * left;
        BinNode * right;

        BinNode(): left(0), right(0){}
        BinNode(T item): data(item), left(0), right(0){}
    };
    
    typedef BinNode * BinNodePointer;
    BinNodePointer myRoot;

    void search2(const T & item, bool & found, BinNodePointer & locptr, BinNodePointer & parent) const;
    void inorderAux(ostream & out, BinNodePointer subtreePtr) const;
    void insertAux(BinNodePointer & myRoot, const T & item);
    void graphAux(ostream & out, int indent, BinNodePointer subtreeRoot) const;

};


template <typename T>
inline BST<T>::BST(): myRoot(0){}


template <typename T>
inline bool BST<T>::empty() const
{ return myRoot == 0; }


template <typename T>
inline void BST<T>::inorder(ostream & out) const
{
    inorderAux(out, myRoot);
}


template <typename T>
void BST<T>::inorderAux(ostream & out, BST<T>::BinNodePointer subtreeRoot) const
{
    if(subtreeRoot != 0)
    {
        inorderAux(out, subtreeRoot->left);
        out << subtreeRoot->data << " ";
        inorderAux(out, subtreeRoot->right);
    }
}


template<typename T>
inline void BST<T>::graph(ostream & out) const
{ graphAux(out, 0, myRoot); }


template<typename T>
void BST<T>::graphAux(ostream & out, int indent, BST<T>::BinNodePointer subtreeRoot) const
{
    if(subtreeRoot != 0)
    {
        graphAux(out, indent + 8, subtreeRoot->right);
        out << setw(indent) << " " <<subtreeRoot->data << endl;
        graphAux(out, indent + 8, subtreeRoot->left);
    }
}


template<typename T>
inline bool BST<T>::search(const T & item) const
{
    BST<T>::BinNodePointer locptr = myRoot;
    bool found = false;
    while(!found && locptr != 0)
    {
        if(item < locptr->data)
            locptr = locptr->left;
        else if (item > locptr->data)
            locptr = locptr->right;
        else
            found = true;
    }
    return found;
}


template<typename T>
void BST<T>::insert(const T & item)
{ insertAux(myRoot, item); }


template<typename T>
void BST<T>::insertAux(BST<T>::BinNodePointer & subtreeRoot, const T & item)
{
    if(subtreeRoot == 0)
        subtreeRoot = new BST<T>::BinNode(item);
    else if(item < subtreeRoot->data)
        insertAux(subtreeRoot->left, item);
    else if(item > subtreeRoot->data)
        insertAux(subtreeRoot->right, item);
    else
        cerr << "Item already in the tree\n";
}


template<typename T>
void BST<T>::remove(const T & item)
{
    bool found;
    BST<T>::BinNodePointer 
        x,  // 指向被删除的节点 
        parent;  // 指向x和xSucc的双亲节点 
    search2(item, found, x, parent);

    if(!found)
    {
        cout << "Item not in the BST\n";
        return;
    }

    if(x->left != 0 && x->right != 0)
    {
        // 查找x中序后继及其双亲节点
        BST<T>::BinNodePointer xSucc = x->right;
        parent = x;
        while (xSucc->left != 0)
        {
            parent = xSucc;
            xSucc = xSucc->left;
        }
        x->data = xSucc->data;
        x = xSucc;
    }    // 节点有两个子女情况处理结束

    // 处理节点没有子女或自由一个子女的情况
    BST<T>::BinNodePointer subtree = x->left;
    if(subtree == 0)
        subtree = x->right;
    if(parent == 0)
        myRoot = subtree;
    else if(parent->left == x)
        parent->left = subtree;
    else
        parent->right = subtree;
    delete x;
}


template<typename T>
void BST<T>::search2(const T & item, bool & found, 
                BST<T>::BinNodePointer & locptr, 
                BST<T>::BinNodePointer & parent) const
{
    locptr = myRoot;
    parent = 0;
    found = false;
    while(!found && locptr != 0)
    {
        if(item < locptr->data)    // 下降到左子树
        {
            parent = locptr;
            locptr = locptr->left;
        }
        else if(item > locptr->data)    // 下降到右子树
        {
            parent = locptr;
            locptr = locptr->right;
        }
        else
            found = true;
    }
}

#endif