#include <fstream>
#include <iostream>
#include <string>
#include <exception>
using namespace std;

bool isCharacter(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '_');
}

// Check if a substring matches the given keyword and is not part of a larger word
bool isKeyword(const string& line, size_t start, const string& keyword) {
    size_t end = start + keyword.size();
    return line.substr(start, keyword.size()) == keyword &&
           (start == 0 || !isCharacter(line[start - 1])) && // Not part of a larger word (prefix check)
           (end >= line.size() || !isCharacter(line[end])); // Not part of a larger word (suffix check)
}

int main() {
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
                } else if (line[i] == '"') { // Handle string literals
                    i++;
                    while (i < line.size() && line[i] != '"') {
                        if (line[i] == '\\' && i + 1 < line.size()) i++; // Skip escaped characters
                        i++;
                    }
                }
            }

            if (skip) break;

            // Check for control flow keywords
            try {
                if (isKeyword(line, i, "while")) {
                    cout << "while:" << row << "," << i + 1 << endl;
                    i += 4; // Skip past "while"
                } else if (isKeyword(line, i, "for")) {
                    cout << "for:" << row << "," << i + 1 << endl;
                    i += 2; // Skip past "for"
                } else if (isKeyword(line, i, "if")) {
                    cout << "if:" << row << "," << i + 1 << endl;
                    i += 1; // Skip past "if"
                }
            } catch (exception& e) {
                cerr << "Exception occurred: " << e.what() << endl;
            }
        }
    }

    return 0;
}
