#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cctype>
using namespace std;
string trimExtraSpaces(const string& str) {
    string result;
    bool inSpace = false;
    for (char ch : str) {
        if (isspace(ch)) {
            if (!inSpace) {
                result += ' ';
                inSpace = true;
            }
        } else {
            result += ch;
            inSpace = false;
        }
    }
    if (!result.empty() && isspace(result.front())) {
        result.erase(result.begin());
    }
    if (!result.empty() && isspace(result.back())) {
        result.erase(result.end() - 1);
    }
    return result;
}

int main()
{
    int place;
    cin >> place;
    cin.get();
    string line;

    while (getline(cin, line))
    {
        size_t colon_pos = line.find(":");
        if (colon_pos != string::npos)
        {
            string left_part = line.substr(0, colon_pos);
            string right_part = line.substr(colon_pos + 1);
            left_part = trimExtraSpaces(left_part);
            right_part = trimExtraSpaces(right_part);
            cout << fixed << right << setw(place) << left_part + " : ";
            cout << right_part << endl;
        }
    }
    return 0;
}
