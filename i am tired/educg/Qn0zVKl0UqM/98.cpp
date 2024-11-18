#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream input("invertsub.in");
    ofstream output("invertsub.out");

    string s, t;
    if (!input.is_open() || !output.is_open())
    {
        cerr << "Error opening files." << endl;
        return 1;
    }

    getline(input, s,'#');
    input.get();
    getline(input, t,'#');

    size_t pos = s.find(t);
    if (pos != string::npos)
    {
        string reversed_t = t;
        reverse(reversed_t.begin(), reversed_t.end());

        s = s.substr(0, pos) + reversed_t + s.substr(pos + t.size());
    }

    output << s << endl;

    input.close();
    output.close();

    return 0;
}
