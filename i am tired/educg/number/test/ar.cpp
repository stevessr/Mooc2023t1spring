#include <iostream>
using namespace std;
int main(int args, char *argv[], char *env[])
{
    cout << args << endl;
    for (int i = 0; i < args; i++)
    {
        cout << argv[i] << endl;
    }
    for (int i = 0; env[i] != nullptr; i++)
    {
        cout << env[i] << endl;
    }
    return 0;
}