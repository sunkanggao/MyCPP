#include <iostream>
#include <iomanip>
using namespace std;

void Move(unsigned n, unsigned & moveNumber, char source, char destination, char spare);


int main()
{
    const char PEG1 = 'A',    // 三个柱子 
               PEG2 = 'B',
               PEG3 = 'C';
    unsigned moveNumber = 0;     // 移动次数计数

    cout << "This program solves the Hanoi Towers puzzle.\n";
    cout << "Enter the number of disks: ";
    int numDisks;
    cin >> numDisks;
    Move(numDisks, moveNumber, PEG1, PEG3, PEG2);
    system("pause");
    return 0;
}


void Move(unsigned n, unsigned & moveNumber, char source, char destination, char spare)
{
    if (n == 1)
    {
        moveNumber++;
        cout << setw(3) << moveNumber
             << ". Move the top disk from " << source
             << " to " << destination << endl;
    }
    else
    {
        Move(n-1, moveNumber, source, spare, destination);
        Move(1, moveNumber, source, destination, spare);
        Move(n-1, moveNumber, spare, destination, source);
    }
}