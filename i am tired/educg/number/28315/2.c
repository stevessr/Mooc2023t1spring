#include <stdio.h>
#include <time.h>
void diffday(int year, int month, int day)
{
    struct tm date = {0};
    // 定义日期
    date.tm_year = year - 1900; // 年份从1900开始计算
    date.tm_mon = month - 1;    // 月份从0开始
    date.tm_mday = day;
    time_t timestamp = mktime(&date);
    char *a = ctime(&timestamp);
    //printf("标准Calendar Time为：%s\n", a);
    switch (a[0])
    {
    case 'M':
        printf("Monday");
        break;
    case 'T':
        if (a[1] == 'u')
        {
            printf("Tuesday");
        }
        else if (a[1] == 'h')
        {
            printf("Thursday");
        }
        break;
    case 'W':
        printf("Wednesday");
        break;
    case 'F':
        printf("Friday");
        break;
    case 'S':
        if (a[1] == 'a')
        {
            printf("Saturday");
        }
        else if (a[1] == 'u')
        {
            printf("Sunday");
        }
        break;
    }
}
int main()
{
    int year, month, day;
    scanf("%d-%d-%d", &year, &month, &day);
    diffday(year, month, day);
    return 0;
}