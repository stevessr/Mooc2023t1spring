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
        return word < dt.word;
    }
};

int main()
{
    ifstream file("crossin.txt");
    string line, word;
    stringstream ss;
    vector<wordclass> words;
    int p = 0, j, extra = 1;
    while (getline(file, line))
    {
        extra = 1;
        p++, j = 1;
        ss = stringstream(line);
        while (ss >> word)
        {
            if (word[0] >= '0' && word[0] <= '9') // Skip numbers
            {
            }
            else if (word == "a" || word == "an" || word == "the" || word == "and") // Skip common words
            {
            }
            else
            {
                if ((word.find(".") != string::npos) || (word.find(",") != string::npos))
                {
                    word.erase(word.length() - 1);
                    extra = 2;
                }
                words.push_back(wordclass(word, "(" + to_string(p) + "," + to_string(j) + ")"));
            }
            j += word.length() + extra;
        }
    }

    unordered_map<string, string> wordMap;
    for (const auto &w : words)
    {
        if (wordMap.find(w.word) != wordMap.end())
        {
            // If word already exists, append the new position with a comma
            wordMap[w.word] += "," + w.line;
        }
        else
        {
            // Otherwise, add the new word with its position
            wordMap[w.word] = w.line;
        }
    }

    // Convert unordered_map to set<wordclass>
    set<wordclass> wordset;
    for (const auto &entry : wordMap)
    {
        wordset.insert(wordclass(entry.first, entry.second));
    }
    ofstream file2("crossout.txt");
    // Output results
    for (const auto &i : wordset)
    {
        file2 << i << endl;
    }
    file2.close();
    return 0;
}
