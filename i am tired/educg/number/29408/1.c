#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char buff[256] = "";
    scanf("%s", buff);
    // printf("%s\n", buff);
    if (isalpha(buff[0]))
    {
        for (int i = 1; i < strlen(buff); i++)
        {
            if (isalpha(buff[i]) || isdigit(buff[i]))
            {
                ;
            }
            else
            {
                printf("0");
                return 0;
            }
        }
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}