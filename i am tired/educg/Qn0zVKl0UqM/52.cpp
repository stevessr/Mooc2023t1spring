#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Student
{
    int id;                     // 学号
    string name;                // 姓名
    int math, english, chinese; // 数学、英语、语文成绩
    int total;                  // 总成绩
    int rank;
};
bool compare(const Student &a, const Student &b)
{
    if (a.total == b.total)
    {
        return a.id > b.id;
    }
    return a.total > b.total;
}

int main()
{
    int n;
    cin >> n;
    if (n >= 10)
    {
        cout << "Please input 1-9." << endl;
        return 0;
    }
    vector<Student> students(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> students[i].id >> students[i].name >> students[i].math >> students[i].english >> students[i].chinese;
        students[i].total = students[i].math + students[i].english + students[i].chinese;
    }
    sort(students.begin(), students.end(), compare);
    int last = 0;
    for (int i = 0; i < n; ++i)
    {
        if (last == students[i].total)
        {
            students[i].rank = students[i - 1].rank;
        }
        else
        {
            students[i].rank = i + 1;
        }
        last = students[i].total;
    }
    for (int i = n - 1; i >= 0; --i)
    {
        cout << setw(4) << students[i].rank
             << setw(10) << students[i].id
             << setw(10) << students[i].name
             << setw(5) << students[i].math
             << setw(5) << students[i].english
             << setw(5) << students[i].chinese
             << endl;
    }

    return 0;
}
