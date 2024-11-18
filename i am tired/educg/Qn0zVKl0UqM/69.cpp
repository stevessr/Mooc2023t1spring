#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ifstream *fin = new ifstream("index.txt");
    string str;
    set<string> index;
    while ((*fin) >> str)
    {
        for (char &c : str)
        {
            c = std::tolower(c);
        }
        index.insert(str);
    }
    (*fin).close();
    fin = new ifstream("in.txt");
    ofstream *ferr = new ofstream("error.txt");
    vector<string> contest;
    while ((*fin) >> str)
    {
        if (str[str.size() - 1] == '.')
        {
            str = str.substr(0, str.size() - 1);
        }
        if (str.find('.') != string::npos || str.find('(') != string::npos || str.find('"') != string::npos || str.find('\'') != string::npos || str.find('9') != string::npos)
        {
            continue;
        }
        for (char &c : str)
        {
            c = std::tolower(c);
        }
        contest.push_back(str);
    }
    vector<string> result;
    for (auto i = contest.rbegin(); i != contest.rend(); i++)
    {
        if (index.find(*i) == index.end())
        {
            result.push_back(*i);
        }
    }
    sort(result.begin(), result.end());
    for (string &i : result)
    {
        *ferr << i << endl;
    }
    return 0;
}