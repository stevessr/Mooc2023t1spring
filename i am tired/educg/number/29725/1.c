// 标识符判断
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool ischarater(char ch)
{
    return ((ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a'));
    // as C did shouble be return ((ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a')|| ch == '_');
}
bool isvaild2(char ch)
{
    return ((ch <= '9' && ch >= '0') || ischarater(ch) );
}
int main()
{
    char ch;
    scanf("%c", &ch);
    if (!ischarater(ch))
    {
        printf("0");
        return 0;
    }
    while (scanf("%c", &ch) && ch != '\n')
    {
        if (!isvaild2(ch))
        {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}