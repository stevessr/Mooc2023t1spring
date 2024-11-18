#include <iostream>
using namespace std;
int main()
{
    char ch;
    cin >> ch;
    switch (ch)
    {
    case 'a':
        cout << 'z';
        break;
    case 'z':
        cout << 'a';
        break;
    case 'c':
        cout << 'y';
        break;
    case 'y':
        cout << 'c';
        break;
    case 'b':
        cout << 'x';
        break;
    case 'x':
        cout << 'b';
        break;
    default:
        break;
    }
    return 0;
}