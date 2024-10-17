#include <iostream>
#include <vector>
using std::cout, std::endl, std::cin, std::string;
int main()
{
    short i;
    cin >> i;
    double rate[i];
    for (int a, b, c = 0; c < i; c++)
    {
        cin >> a >> b;
        rate[c]=b / double(a);
    }
    double differ;
    for (int c = 1; c < i; c++)
    {
        differ = rate[0] - rate[c];
        cout<<differ;
        if (differ > 0.05)
        {
            cout << "better";
        }
        else if (differ < -0.05)
        {
            cout << "worse";
        }
        else
        {
            cout << "same";
        }
        cout << endl;
    }

    return 0;
}