#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 判断字符串是否是负数
bool isNegative(const string& s) {
    return s[0] == '-';
}

// 绝对值加法
string addAbs(string a, string b) {
    if (a.length() < b.length()) swap(a, b);

    int carry = 0;
    string result = "";

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i] - '0';
        if (j >= 0) sum += b[j] - '0';

        carry = sum / 10;
        result += (sum % 10) + '0';

        i--;
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

// 绝对值减法
string subtractAbs(string a, string b) {
    bool negative = false;
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        swap(a, b);
        negative = true;
    }

    int borrow = 0;
    string result = "";

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0) {
        int diff = a[i] - '0' - borrow;
        if (j >= 0) diff -= b[j] - '0';

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result += diff + '0';
        i--;
        j--;
    }

    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    if (negative) result += '-';
    reverse(result.begin(), result.end());
    return result;
}

// 绝对值乘法
string multiplyAbs(string a, string b) {
    int lenA = a.length();
    int lenB = b.length();

    string result(lenA + lenB, '0');

    for (int i = lenA - 1; i >= 0; i--) {
        for (int j = lenB - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');

            result[i + j + 1] = sum % 10 + '0';
            result[i + j] += sum / 10;
        }
    }

    size_t start = result.find_first_not_of('0');
    if (start != string::npos) {
        return result.substr(start);
    }
    return "0";
}

// 检查并移除多余的负号
string removeExtraNegative(string result) {
    // 如果结果以两个负号开始，就去掉第一个负号
    if (result.length() > 1 && result[0] == '-' && result[1] == '-') {
        result = result.substr(2); // 移除多余的负号
    }
    return result;
}

string add(string a, string b) {
    bool negA = isNegative(a);
    bool negB = isNegative(b);

    string result;
    if (!negA && !negB) {
        // 两个正数相加
        result = addAbs(a, b);
    } else if (negA && negB) {
        // 两个负数相加
        result = "-" + addAbs(a.substr(1), b.substr(1));
    } else {
        // 一个正数一个负数
        if (negA) {
            result = subtractAbs(b, a.substr(1));
        } else {
            result = subtractAbs(a, b.substr(1));
        }
    }
    
    return removeExtraNegative(result); // 移除多余的负号
}

string subtract(string a, string b) {
    bool negA = isNegative(a);
    bool negB = isNegative(b);

    string result;
    if (!negA && !negB) {
        // 两个正数相减
        if (a >= b) {
            result = subtractAbs(a, b);
        } else {
            result = "-" + subtractAbs(b, a);
        }
    } else if (negA && negB) {
        // 两个负数相减
        if (a >= b) {
            result = "-" + subtractAbs(a.substr(1), b.substr(1));
        } else {
            result = subtractAbs(b.substr(1), a.substr(1));
        }
    } else {
        // 一个正数一个负数
        if (negA) {
            result = "-" + addAbs(a.substr(1), b);
        } else {
            result = addAbs(a, b.substr(1));
        }
    }

    return removeExtraNegative(result); // 移除多余的负号
}

string multiply(string a, string b) {
    bool negA = isNegative(a);
    bool negB = isNegative(b);

    string result = multiplyAbs(a.substr(negA ? 1 : 0), b.substr(negB ? 1 : 0));

    // 结果的符号由负号的数量决定
    if (negA != negB && result != "0") {
        result = "-" + result;
    }

    return removeExtraNegative(result); // 移除多余的负号
}

int main() {
    string M, N, op;
    cin >> M >> op >> N;

    string result;
    if (op == "+") {
        result = add(M, N);
    } else if (op == "-") {
        result = subtract(M, N);
    } else if (op == "*") {
        result = multiply(M, N);
    }

    cout << result << endl;

    return 0;
}
