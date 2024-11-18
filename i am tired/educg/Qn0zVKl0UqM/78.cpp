#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
string truncateNumber(const string& numberStr, int precision) {
    size_t dotPos = numberStr.find('.');
    if (dotPos == string::npos) {
        return numberStr + "." + string(precision, '0');
    }

    string integerPart = numberStr.substr(0, dotPos);
    string decimalPart = numberStr.substr(dotPos + 1);
    if (decimalPart.size() > precision) {
        decimalPart = decimalPart.substr(0, precision);
    } else {
        decimalPart += string(precision - decimalPart.size(), '0');
    }

    return integerPart + "." + decimalPart;
}
string formatNumber(const string& numberStr, const string& formatString) {
    size_t percentIndex = formatString.find('%');
    size_t fIndex = formatString.find('f');
    if (percentIndex == string::npos || fIndex == string::npos || fIndex <= percentIndex) {
        throw invalid_argument("Invalid format string");
    }

    bool leftAlign = formatString.find('-') != string::npos;
    size_t dotIndex = formatString.find('.');
    int width = 0;
    int precision = 10; 
    if (dotIndex != string::npos) {
        width = stoi(formatString.substr(percentIndex + 1, dotIndex - percentIndex - 1));
    } else {
        width = stoi(formatString.substr(percentIndex + 1, fIndex - percentIndex - 1));
    }
    if (dotIndex != string::npos) {
        precision = stoi(formatString.substr(dotIndex + 1, fIndex - dotIndex - 1));
    }
    string formattedNumber = truncateNumber(numberStr, precision);
    if (width > static_cast<int>(formattedNumber.size())) {
        int padding = width - formattedNumber.size();
        string paddingStr(padding, '*');
        if (leftAlign) {
            formattedNumber += paddingStr;
        } else {
            formattedNumber = paddingStr + formattedNumber;
        }
    }

    return formattedNumber;
}

int main() {
    ifstream inputFile("in.txt");
    if (!inputFile) {
        cerr << "Failed to open in.txt" << endl;
        return 1;
    }

    string numberStr;
    string formatString;
    getline(inputFile, numberStr);
    getline(inputFile, formatString);

    inputFile.close();

    try {
        string result = formatNumber(numberStr, formatString);
        cout << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
