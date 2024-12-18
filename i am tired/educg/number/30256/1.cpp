// Julius文件加密
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
bool encypt(char &i, int key)
{
    if (i >= 'a' && i <= 'z')
    {
        i = 'a' + (i - 'a' + key) % 26;
        return true;
    }
    else if (i >= 'A' && i <= 'Z')
    {
        i = 'A' + (i - 'A' + key) % 26;
        return true;
    }
    return false;
}
int main()
{
    int key;
    cin >> key;
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    string str;
    while (getline(fin, str))
    {
        for (auto &i : str)
        {
            encypt(i, key);
        }
        fout << str << endl;
    }
    fin.close();
    fout.close();
    return 0;
}