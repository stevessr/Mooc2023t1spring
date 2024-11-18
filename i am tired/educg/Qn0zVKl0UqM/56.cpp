#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string caesarCipherEncrypt(int key, const string& text) {
    string encryptedText = text;
    
    for (char &ch : encryptedText) {
        if ('A' <= ch && ch <= 'Z') {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        else if ('a' <= ch && ch <= 'z') {
            ch = (ch - 'a' + key) % 26 + 'a';
        }
    }
    
    return encryptedText;
}

int main() {
    int key;
    cout << "请输入加密密钥（1到25之间的整数）：";
    cin >> key;
    if (key < 1 || key > 25) {
        cout << "密钥必须在1到25之间！" << endl;
        return 1;
    }
    ifstream infile("in.txt");
    if (!infile) {
        cerr << "无法打开文件 in.txt！" << endl;
        return 1;
    }
    ofstream outfile("out.txt");
    if (!outfile) {
        cerr << "无法创建文件 out.txt！" << endl;
        return 1;
    }
    string line;
    while (getline(infile, line)) {
        string encryptedLine = caesarCipherEncrypt(key, line);
        outfile << encryptedLine << endl;
    }
    infile.close();
    outfile.close();
    cout << "加密完成，结果已保存至 out.txt。" << endl;

    return 0;
}
