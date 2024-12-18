#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addLargeNumbers(const string &num1, const string &num2) {
    string result = "";
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0; 
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        int sum = digit1 + digit2 + carry; 
        carry = sum / 10;                 
        result += (sum % 10) + '0';      
    }

    reverse(result.begin(), result.end());
    while(result[0] == '0'){
        result = result.substr(1);
    }
    return result;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    string sum = addLargeNumbers(num1, num2);
    cout << sum << endl;

    return 0;
}
