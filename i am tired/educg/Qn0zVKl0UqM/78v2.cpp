#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void parseFormat(const string& format, bool& leftAlign, int& width, int& precision) {
    leftAlign = false;
    width = 0;
    precision = 10;

    size_t pos = format.find('.');
    if (pos != string::npos) {
        string precStr = format.substr(pos + 1, format.size() - pos - 2);
        precision = stoi(precStr);
    }

    if (format[1] == '-') {
        leftAlign = true;
        width = stoi(format.substr(2, pos - 2));
    } else {
        width = stoi(format.substr(1, pos - 1));
    }
}

int main() {
    ifstream infile("in.txt");
    if (!infile.is_open()) {
        cerr << "无法打开文件 in.txt" << endl;
        return 1;
    }

    string numberStr, formatStr;
    getline(infile, numberStr);
    getline(infile, formatStr);

    long double number = stold(numberStr); // 使用 long double
    bool leftAlign;
    int width, precision;
    parseFormat(formatStr, leftAlign, width, precision);

    cout << fixed << setprecision(precision);
    if (leftAlign) {
        cout << setw(width) << setfill('*') << right << number;
    } else {
        cout << setw(width) << setfill('*') << left << number;
    }

    return 0;
}