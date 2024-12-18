#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> prefix_function(string &s)
{
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i = 1, j; i < n; i++)
    {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
int main()
{
    string word, centense, smallcentnese = "";
    cin >> word;
    cin >> centense;
    // cout<<word<<endl<<centense<<endl;
    for (auto &i : centense)
    {
        smallcentnese += i;
        i = tolower(i);
    }
    for (auto &i : word)
    {
        i = tolower(i);
    }
    vector<int> next = prefix_function(word);
    for (int i = 0, j = 0; i < centense.size(); i++)
    {
        while (j > 0 && centense[i] != word[j])
        {
            j = next[j - 1];
        }
        if (centense[i] == word[j])
        {
            j++;
        }
        if (j == word.size())
        {
            if ((i - j + 1) == 0)
            {
            }
            else if (centense[i - j] != ' ')
            {
                centense.insert(i - j + 1, " ");
                smallcentnese.insert(i - j + 1, " ");
                i++;
            }
            if ((i + 3) >= centense.size())
            {
            }
            else
            {
                centense.insert(i + 1, " ");
                smallcentnese.insert(i + 1, " ");
            }

            // cout<<i-j+1<<endl;
            // j = next[j - 1];
            j = 0;
        }
    }
    cout << smallcentnese;
    return 0;
}