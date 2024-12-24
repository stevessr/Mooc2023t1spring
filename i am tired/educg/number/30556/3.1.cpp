#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string scientificToDecimal(string scientific) {
    // 找到'e'或'E'的位置
    int ePos = scientific.find('e');
    if (ePos == string::npos) ePos = scientific.find('E');
    
    // 分离底数和指数
    string base = scientific.substr(0, ePos);
    string exp = scientific.substr(ePos + 1);
    
    // 处理指数
    int exponent = stoi(exp);
    
    // 处理底数
    bool isNegative = false;
    if (base[0] == '-') {
        isNegative = true;
        base = base.substr(1);
    } else if (base[0] == '+') {
        base = base.substr(1);
    }
    
    // 找到小数点位置
    int dotPos = base.find('.');
    string result;
    
    // 移除小数点
    base.erase(dotPos, 1);
    
    // 计算新的小数点位置
    int newDotPos = dotPos + exponent;
    
    // 根据新的小数点位置构建结果
    if (newDotPos <= 0) {
        // 需要在前面补0
        result = "0.";
        for (int i = 0; i < -newDotPos; i++) {
            result += "0";
        }
        result += base;
    } else if (newDotPos >= base.length()) {
        // 需要在后面补0
        result = base;
        for (int i = 0; i < newDotPos - base.length(); i++) {
            result += "0";
        }
    } else {
        // 在中间插入小数点
        result = base.substr(0, newDotPos) + "." + base.substr(newDotPos);
    }
    
    // 去除末尾的0
    if (result.find('.') != string::npos) {
        while (result.back() == '0') {
            result.pop_back();
        }
        if (result.back() == '.') {
            result.pop_back();
        }
    }
    
    // 添加负号
    if (isNegative) {
        result = "-" + result;
    }
    
    return result;
}

int main() {
    string input;
    cin >> input;
    cout << scientificToDecimal(input) << endl;
    return 0;
}