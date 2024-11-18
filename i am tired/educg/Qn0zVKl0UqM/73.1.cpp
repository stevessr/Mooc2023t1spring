#include <fstream>
#include <iostream>
#include <string>
#include <exception>
using namespace std;

bool isCharacter(char ch)
{
    return ((ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a') || (ch >= '0' && ch <= '9'));
}

int main()
{
    ifstream fin("in.c");
    if (!fin.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    int row = 0;

    while (getline(fin, line)) {
        row++;
        bool skip = false;

        for (size_t i = 0; i < line.size(); i++) {
            if (!isCharacter(line[i])) {
                // Handle comments
                if (line[i] == '/' && i + 1 < line.size()) {
                    if (line[i + 1] == '/') { // Single-line comment
                        skip = true;
                        break;
                    } else if (line[i + 1] == '*') { // Multi-line comment
                        i += 2;
                        while (true) {
                            if (i >= line.size()) {
                                if (!getline(fin, line)) break;
                                i = 0;
                                row++;
                            }
                            if (line[i] == '*' && i + 1 < line.size() && line[i + 1] == '/') {
                                i++;
                                break;
                            }
                            i++;
                        }
                        continue;
                    }
                }
            }

            if (skip) break;

            try {
                // Check for "gets"
                if (line[i] == 'g' && i + 2 < line.size() && line[i + 1] == 'e' && line[i + 2] == 't') {
                    i += 3;
                    if (i < line.size() && line[i] == 's' && (i + 1 >= line.size() || !isCharacter(line[i + 1]))) {
                        cout << "gets:" << row << "," << i - 2 << endl;
                    } else if (i + 3 < line.size() && line[i] == 'c' && line[i + 1] == 'h' && line[i + 2] == 'a' && line[i + 3] == 'r' &&
                               (i + 4 >= line.size() || !isCharacter(line[i + 4]))) {
                        cout << "getchar:" << row << "," << i - 2 << endl;
                    }
                }
                // Check for "scanf"
                else if (line[i] == 's' && i + 4 < line.size() && line[i + 1] == 'c' && line[i + 2] == 'a' && line[i + 3] == 'n' &&
                         line[i + 4] == 'f' && (i + 5 >= line.size() || !isCharacter(line[i + 5]))) {
                    cout << "scanf:" << row << "," << i + 1 << endl;
                } else {
                    while (i < line.size() && isCharacter(line[i])) {
                        i++;
                    }
                }
            } catch (exception& e) {
                cerr << "Exception occurred: " << e.what() << endl;
            }
        }
    }

    return 0;
}
