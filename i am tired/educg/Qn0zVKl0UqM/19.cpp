#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string str;
    cin >> str;
    short len = static_cast<short>(str.length());
    bool pass = true;
    if (str == "0")
    {
        pass = false;
        cout << 1;
        return 0;
    }
    for (unsigned long long i = len - 1; pass; i--)
    {
        switch (str[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
            str[i] += 1;
            pass = false;
            break;
        case '9':
            str[i] = '0';
            break;
        }
        if (i == 0)
        {
            cout << 1;
            pass = false;
        }
    }
    cout << str;
    return 0;
}