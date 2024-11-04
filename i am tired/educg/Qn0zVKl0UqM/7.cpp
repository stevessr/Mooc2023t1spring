#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class student
{
public:
    int score;
    string name;
    student()
    {
    }
    void update()
    {
        int s1, s2, s3;
        cin >> name >> s1 >> s2 >> s3;
        score = s1 + s2 + s3;
    }
    void output()
    {
        cout << name << " " << score;
    }

private:
};
bool StdentCopare(const student &s1,const student &s2)
{
    if (s1.score != s2.score)
    {
        return s1.score > s2.score;
    }
    else
    {
        return (s1.name[0] < s2.name[0]);
    }
}
int main()
{
    vector<student> stuvet;
    int T;
    student temp;
    cin >> T;
    while (T--)
    {
        temp.update();
        stuvet.push_back(temp);
    }

    sort(stuvet.begin(), stuvet.end(), StdentCopare);
    cin >> T;
    stuvet[T - 1].output();
    return 0;
}
