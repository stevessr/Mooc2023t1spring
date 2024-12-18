// 1. 扩展速记符
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isnumber(char c)
{
    return c >= '0' && c <= '9';
}

bool isalphaS(char c)
{
    return (c >= 'a' && c <= 'z');
}
bool isalphaB(char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool isavailable(char c)
{
    return (isalphaB(c) || isalphaS(c) || isnumber(c));
}

void expand(char *str, char *result)
{
    for (int temp = 0, right = 0, i = 0; str[right] != '\n';)
    {
        if (str[right] == '-')
        {
            if (str[right + 1] == '\n')
            {
                continue;
            }
            else if (isnumber(str[right + 1]) && isnumber(str[right - 1]) && str[right + 1] > str[right - 1])
            {
                for (char begin = str[right - 1] + 1; begin < str[right + 1]; begin++)
                {
                    result[i++] = begin;
                }
                right++;
            }
            else if (isalphaB(str[right + 1]) && isalphaB(str[right - 1]) && str[right + 1] > str[right - 1])
            {
                for (char begin = str[right - 1] + 1; begin < str[right + 1]; begin++)
                {
                    result[i++] = begin;
                }
                right++;
            }
            else if (isalphaS(str[right + 1]) && isalphaS(str[right - 1]) && str[right + 1] > str[right - 1])
            {
                for (char begin = str[right - 1] + 1; begin < str[right + 1]; begin++)
                {
                    result[i++] = begin;
                }
                right++;
            }
            else
            {
                result[i++] = str[right++];
            }
        }
        else
        {
            result[i++] = str[right++];
        }
    }
}

void expand2(char *str, char *result)
{
    for (int temp = 0, right = 0, i = 0; str[right] != '\0';)
    {
        if (str[right] == '-')
        {
            if (str[right + 1] == '\0')
            {
                continue;
            }
            else if (isavailable(str[right - 1]) && isavailable(str[right + 1]) && (str[right + 1] > str[right - 1]))
            {
                for (char begin = str[right - 1] + 1; begin < str[right + 1]; begin++)
                {
                    result[i++] = begin;
                }
                right++;
            }
            else
            {
                result[i++] = str[right++];
            }
        }
        else
        {
            result[i++] = str[right++];
        }
    }
}
int main()
{
    char buff1[300]="", buff2[300]="";
    fgets(buff1, 300, stdin);
    expand2(buff1, buff2);
    printf("%s\n", buff2);
    return 0;
}