#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // 用于格式化输出
using namespace std;

class Date
{
public:
    Date(string dated)
    {
        this->year = (dated[0] - '0') * 1000 + (dated[1] - '0') * 100 + (dated[2] - '0') * 10 + (dated[3] - '0');
        this->month = (dated[4] - '0') * 10 + (dated[5] - '0');
        this->day = (dated[6] - '0') * 10 + (dated[7] - '0');
    }

    void update(long pass = 0)
    {
        do
        {
            updateDay(pass);
        } while (month > 3);
        while (updateYear(pass))
            ;
        while (updateDay(pass))
            ;
    }

    void output() const
    {
        if (year > 9999)
        {
            cout << "out of limitation!";
        }
        else
        {
            cout << setw(4) << setfill('0') << year
                 << setw(2) << setfill('0') << month
                 << setw(2) << setfill('0') << day;
        }
    }

private:
    int year, month, day;

    bool updateYear(long &pass)
    {
        int daysInYear = isLeapYear(year) ? 366 : 365;
        if (pass >= daysInYear)
        {
            pass -= daysInYear;
            year++;
            return true;
        }
        return false;
    }

    bool updateDay(long &pass)
    {
        int daysInMonth = getDaysInMonth(year, month);
        if (pass >= (daysInMonth - day + 1))
        {
            pass -= (daysInMonth - day + 1);
            day = 1;
            if (++month > 12)
            {
                month = 1;
                year++;
            }
            return true;
        }
        else
        {
            day += pass;
            pass = 0;
            return false;
        }
    }

    bool isLeapYear(int year) const
    {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    int getDaysInMonth(int year, int month) const
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
        }
    }
};

int main()
{
    string strline;
    getline(cin, strline);
    istringstream line(strline);
    string dated;
    long passday;

    line >> dated >> passday;
    Date old(dated);
    old.update(passday);
    old.output();

    return 0;
}
