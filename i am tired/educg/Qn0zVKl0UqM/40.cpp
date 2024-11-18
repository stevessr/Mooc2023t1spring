#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
class wordclass
{
public:
    string word;
    string line;
    wordclass(string WORD, string LINE) : word(WORD), line(LINE) {}
    friend ostream &operator<<(ostream &os, const wordclass &dt)
    {
        os << dt.word + ":" + dt.line;
        return os;
    }
    bool operator<(const wordclass &dt) const
    {
        return word[0] < dt.word[0];
    }
};
int main()
{
    ifstream file("crossin.txt");
    string line, word;
    stringstream ss;
    vector<wordclass> words;
    int p, j;
    char ch;
    while (getline(file, line))
    {
        p++, j = 1;
        /*for (auto &f : line){if (f == '-'){f = ' ';}}//*/
        ss = stringstream(line);
        while (ss >> word)
        {

            if (word[0] >= '0' && word[0] <= '9')
            {
            }
            else if (word == "a" || word == "an" || word == "the" || word == "and")
            {
            }
            else
            {
                if ((word.find(".") != string::npos) || (word.find(",") != string::npos))
                {
                    word.erase(word.length() - 1);
                    j++;
                }
                words.push_back(wordclass(word, "(" + to_string(p) + "," + to_string(j) + ")"));
            }
            j += word.length() + 1;
        }
    }
    set<wordclass> wordset;
    for (auto &i : words)
    {
        wordset.insert(i);// need top fix
    }
    for (auto &i : wordset)
    {
        cout << i << endl;
    }
    return 0;
}