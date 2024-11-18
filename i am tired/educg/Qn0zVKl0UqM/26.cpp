#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
using namespace std;
int main()
{
    string str;
    char ch;
    cin >> str;
    int i = 0, len = str.length();
    ifstream file1;
    ofstream file2;
    file1.open("1txt");
    file2.open("2txt");
    while (file1.get(ch))
    {
        file2 << char(ch ^ (str[i++]));
        if (i == len)
        {
            i = 0;
        }
    }
    file1.close(), file2.close();
    return 0;
}