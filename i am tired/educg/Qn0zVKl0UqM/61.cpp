#include <iostream>
using namespace std;
struct date
{
    int year, month, day, actday;
};
int main()
{
    date d1;
    cin >> d1.year >> d1.month >> d1.day;
    d1.actday = d1.day;
    switch (d1.month)
    {
    case 12:
        d1.actday += 30;
    case 11:
        d1.actday += 31;
    case 10:
        d1.actday += 30;
    case 9:
        d1.actday += 31;
    case 8:
        d1.actday += 31;
    case 7:
        d1.actday += 30;
    case 6:
        d1.actday += 31;
    case 5:
        d1.actday += 30;
    case 4:
        d1.actday += 31;
    case 3:
        if (d1.year % 400 == 0 || (d1.year % 4 == 0 && d1.year % 100 != 0))
            d1.actday += 29;
        else
            d1.actday += 28;
    case 2:
        d1.actday += 31;
    case 1:
        break;
    default:
        break;
    }
    cout << d1.actday;
    return 0;
}
