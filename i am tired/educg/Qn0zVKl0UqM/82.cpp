#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
void generateCipherAlphabet(const string &key, string &cipherAlphabet) {
    unordered_set<char> used; 
    string uniqueKey;

    for (char ch : key) {
        if (used.find(ch) == used.end()) {
            uniqueKey += ch;
            used.insert(ch);
        }
    }

    string remainingLetters;
    for (char ch = 'z'; ch >= 'a'; --ch) {
        if (used.find(ch) == used.end()) {
            remainingLetters += ch;
        }
    }

    cipherAlphabet = uniqueKey + remainingLetters;
}

void encryptContent(const string &content, const string &cipherAlphabet, string &encryptedContent) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    unordered_map<char, char> cipherMap;

    for (size_t i = 0; i < alphabet.size(); ++i) {
        cipherMap[alphabet[i]] = cipherAlphabet[i];
    }

    encryptedContent.clear();
    for (char ch : content) {
        if (isalpha(ch)) {
            encryptedContent += cipherMap[ch];
        } else {
            encryptedContent += ch; 
        }
    }
}

int main() {
    string key;
    cin >> key;

    ifstream inputFile("encrypt.txt");
    if (!inputFile) {
        cerr << "Error opening encrypt.txt" << endl;
        return 1;
    }

    string content;
    string line;
    while (getline(inputFile, line)) {
        content += line + '\n';
    }
    inputFile.close();

    string cipherAlphabet;
    generateCipherAlphabet(key, cipherAlphabet);

    string encryptedContent;
    encryptContent(content, cipherAlphabet, encryptedContent);

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }
    outputFile << encryptedContent;
    outputFile.close();

    cout << "Encryption complete. Output saved to output.txt" << endl;
    return 0;
}
