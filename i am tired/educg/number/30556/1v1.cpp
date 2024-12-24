#include <iostream>
#include <string>
#include <algorithm>

// 用来进行超长整数减法
std::string subtractBigIntegers(const std::string& num1, const std::string& num2) {
    // 确保num1大于num2，如果不是就交换 
    bool isNegative = false;
    std::string larger, smaller;

    if (num1.length() > num2.length() || (num1.length() == num2.length() && num1 > num2)) {
        larger = num1;
        smaller = num2;
    } else {
        larger = num2;
        smaller = num1;
        isNegative = true;
    }

    // 反转两个字符串以方便从低位开始减法
    std::reverse(larger.begin(), larger.end());
    std::reverse(smaller.begin(), smaller.end());

    // 补零到较短数的长度
    smaller.append(larger.length() - smaller.length(), '0');

    int borrow = 0;
    std::string result = "";

    // 逐位相减
    for (size_t i = 0; i < larger.length(); i++) {
        int digit1 = larger[i] - '0';
        int digit2 = smaller[i] - '0';

        digit1 -= borrow;
        if (digit1 < digit2) {
            borrow = 1;
            digit1 += 10;
        } else {
            borrow = 0;
        }

        int digit = digit1 - digit2;
        result.push_back(digit + '0');
    }

    std::reverse(result.begin(), result.end());
    size_t start = result.find_first_not_of('0');
    if (start != std::string::npos) {
        result = result.substr(start);
    } else {
        result = "0";
    }

    if (isNegative && result != "0") {
        result = "-" + result;
    }

    return result;
}

int main() {
    std::string num1, num2;

    std::cin >> num1;
    std::cin >> num2;

    std::string result = subtractBigIntegers(num1, num2);

    std::cout << result << std::endl;

    return 0;
}
