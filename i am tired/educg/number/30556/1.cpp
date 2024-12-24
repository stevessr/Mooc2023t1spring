#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string minux(const string &A, const string &B)
{
    if (A == B)
    {
        return "0";
    }
    if (A.size() < B.size() || (A.size() == B.size() && A[0] < B[0]))
    {
        return "-" + minux(B, A);
    }
    string At = A, Bt = B;
    string result = "0";
    result.resize(80);
    reverse(At.begin(), At.end());
    reverse(Bt.begin(), Bt.end());
    for (size_t i = 0; i < Bt.size(); i++)
    {
        if (At[i] >= Bt[i])
        {
            result[i] = (At[i] - Bt[i] + '0');
        }
        else
        {
            result[i] = (At[i] - Bt[i] + 10 + '0');
            if (At[i] > '0')
            {
                At[i]--;
            }
            else
            {
                for (int j = i; At[j] > '0'; j++)
                {
                    At[j] = '9';
                    if (At[j + 1] > '0')
                    {
                        At[j + 1]--;
                        break;
                    }
                }
            }
        }
    }
    for (int i = Bt.size(); i < At.size(); i++)
    {
        result[i] = At[i];
    }
    reverse(result.begin(), result.end());
    while (result[0] == '0')
    {
        result = result.substr(1);
    }
    return result;
}

int main()
{
    string A, B;
    cin >> A >> B;
    string result = minux(A, B);
    cout << result;
}