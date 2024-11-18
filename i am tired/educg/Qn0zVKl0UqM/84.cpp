#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string str, flower = "";
    bool f = true;
    int leftCount = 0, rightCount = 0; 
    ifstream fin("input.c");

    if (!fin) {
        cerr << "Failed to open file input.c" << endl;
        return 1;
    }

    bool inComment = false;
    while (getline(fin, str)) {
        for (size_t i = 0; i < str.length(); i++) {
            if (!inComment) {
                if (str[i] == '/' && i + 1 < str.length() && str[i + 1] == '/') {
                    break;
                }

                if (str[i] == '/' && i + 1 < str.length() && str[i + 1] == '*') {
                    inComment = true;
                    i++;
                    continue;
                }


                if (str[i] == '{') {
                    flower += "{";
                    leftCount++;
                } else if (str[i] == '}') {
                    flower += "}";
                    rightCount++;
                    if (rightCount > leftCount) {
                        f = false;
                    }
                }
            } else {
                if (str[i] == '*' && i + 1 < str.length() && str[i + 1] == '/') {
                    inComment = false;
                    i++;
                }
            }
        }
    }

    fin.close();
    if (leftCount != rightCount) {
        f = false; 
    }

    cout << f << endl << flower << endl;
    return 0;
}
