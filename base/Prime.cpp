#include <iostream>
#include <cmath>
using namespace std;

bool Prime(int a)
{
    int b = int(sqrt(a));
    for(int i = 2; i <= b; i++)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int a;
    while(cin >> a)
    {
        if(a < 2)
            cout << "The input number is smaller than 2." << endl;
        if(a == 2)
            cout << "Not Prime" << endl;
        else if(Prime(a))
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
    }
    return 0;
}