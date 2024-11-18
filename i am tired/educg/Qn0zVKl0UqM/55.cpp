#include <fstream>
#include <string>
#include <iostream>
#include <set>
using namespace std;
struct after
{
    char se[26];
};

int main()
{
    ifstream fin("encrypt.txt");
    ofstream fout("output.txt");
    string key, todo, ency;
    cin >> key;
    getline(fin, todo);
    set<char> doit;
    for (auto &i : key)
    {
        if (ency.find(i) == -1)
        {
            ency += i;
        }
    }
    for (char i = 'z'; i >= 'a'; i--)
    {
        if (ency.find(i) == -1)
        {
            ency += i;
        }
    }
    for (auto &i : todo)
    {
        if (i >= 'a' && i <= 'z')
        {
            cout << ency[i - 'a'];
            fout << ency[i - 'a'];
        }
        else
        {
            cout << i;
            fout << i;
        }
    }
    return 0;
}