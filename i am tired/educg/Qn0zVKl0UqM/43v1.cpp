#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool minu = false;

string removeLeadingZeros(string &num)
{
    if (num[0] == '-')
    {
        minu = !minu;
        num = num.substr(1);
    }
    size_t first_non_zero = num.find_first_not_of('0');
    if (first_non_zero == string::npos)
        return "0";
    return num.substr(first_non_zero);
}

int main()
{
    string num1, num2;
    getline(cin, num1);
    getline(cin, num2);
    num1 = removeLeadingZeros(num1);
    num2 = removeLeadingZeros(num2);

    if (num1 == "0" || num2 == "0")
    {
        cout << "0";
        return 0;
    }

    int n = num1.size();
    int m = num2.size();
    vector<int> result(n + m, 0);

    string a = string(num1.rbegin(), num1.rend());
    string b = string(num2.rbegin(), num2.rend());
    {
        int digit_a, digit_b, i, j;
        for (i = 0; i < a.size(); ++i)
        {
            digit_a = a[i] - '0';
            for (j = 0; j < b.size(); ++j)
            {
                digit_b = b[j] - '0';
                result[i + j] += digit_a * digit_b;
                if (result[i + j] >= 10)
                {
                    result[i + j + 1] += result[i + j] / 10;
                    result[i + j] %= 10;
                }
            }
        }
    }

    // Handle any remaining carry
    for (int i = 0; i < result.size(); ++i)
    {
        if (result[i] >= 10)
        {
            if (i + 1 == result.size())
            {
                result.push_back(0);
            }
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    if (minu)
    {
        cout << "-";
    }
    int highest = result.size() - 1;
    while (highest > 0 && result[highest] == 0)
    {
        highest--;
    }

    for (int i = highest; i >= 0; --i)
    {
        cout << result[i];
    }

    return 0;
}
