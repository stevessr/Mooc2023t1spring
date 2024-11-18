#include <iostream>
#include <unistd.h> // For UNIX/Linux systems
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool fu = false;
int scan(string &s);
string multiply(string &s1, string &s2);
string add(string &s1, string &s2);
int main()
{
    string str1, str2, temp = "";
    cin >> str1 >> str2;
    scan(str1), scan(str2);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int str10 = scan(str1) + scan(str2);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    if (fu)
    {
        cout << "-";
    }
    if (str1.length() > str2.length())
    {
        cout << multiply(str1, str2);
    }
    else
    {
        cout << multiply(str2, str1);
    }
    while (str10--)
    {
        cout << "0";
    }
    return 0;
}
int scan(string &s)
{
    int j = s.length() - 1;
    if (s[0] == '-')
    {
        s = s.substr(1);
        fu = !fu;
    }
    if (s[0] != '0')
    {
        return 0;
    }
    for (int i = 0; i < j; i++)
    {
        if (s[i] != '0')
        {
            s = s.substr(i);
            return i;
        }
    }
}
string multiply(string &s1, string &s2) // s1 > s2
{
    int imax = s1.length(), jmax = s2.length(), temper, nextime = 0;
    string temp = "0", caculatetemp = "0";
    for (int j = 0; j < jmax; j++)
    {
        for (int i = 0; i < imax; i++)
        {
            temper = (s1[i] - '0') * (s2[j] - '0');
            temper += nextime;
            nextime = 0;
            if (temper > 10)
            {
                nextime = temper / 10;
                temper %= 10;
            }
            caculatetemp[i] = temper + '0';
        }
        reverse(caculatetemp.begin(), caculatetemp.end());
        temp = add(temp, caculatetemp);
    }
    return temp;
}
string add(string &s1, string &s2)
{
    int imax = s1.length(), jmax = s2.length();
    int maxer = max(imax,jmax);
    string temp = "";
    for (int i = 0; i < maxer; i++)
    {
        if (jmax - i - 1 >= 0)
        {
            temp += s1[imax - i - 1] + s2[jmax - i - 1] - '0';
        }
        else
        {
            temp += s1[imax - i - 1];
        }
    }
    reverse(temp.begin(), temp.end());
    return temp;
}