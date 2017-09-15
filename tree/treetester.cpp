#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
    BST<int> intBST;
    cout << "Constructing empty BST\n";
    cout << "BST" << (intBST.empty() ? " is" : "is not") << " empty\n";

    // 测试中序遍历
    cout << "Inorder Traversal of BST: \n";
    intBST.inorder(cout);
    
    // 测试插入操作
    cout << "\nNow insert a bunch of integers into the BST.";
    cout << "\nTry items not in the BST and some that are in it:\n";
    int number;
    for(;;)
    {
        cout << "Item to insert (-999 to stop): ";
        cin >> number;
        if(number == -999) break;
        intBST.insert(number);
    }
    intBST.graph(cout);

    cout << "BST " << (intBST.empty()? "is" : "is not") << " empty\n";
    cout << "Inorder Traversal of BST: \n";
    intBST.inorder(cout);
    cout << endl;

    // 测试search()
    cout << "\n\nNow testing the search() operation.";
    cout << "\nTry both items in the BST and some not in it:\n";
    for(;;)
    {
        cout << "Item to find(-999 to stop): ";
        cin >> number;
        if(number == -999) break;
        cout << (intBST.search(number)? "Found" : "Not Found") << endl;
    }

    // 测试remove()
    cout << "\n\nNow testing the remove() operation.";
    cout << "\nTry both items in the BST and some not in it:\n";
    for(;;)
    {
        cout << "Item to remove(-999 to stop): ";
        cin >> number;
        if(number == -999) break;
        intBST.remove(number);
        intBST.graph(cout);
    }
    cout << "Inorder Traversal of BST: \n";
    intBST.inorder(cout);
    cout << endl;

    system("pause");
    return 0;
}