// 2. 字符串位置的查询
#include <stdio.h>
#include <string.h>
int main()
{
    char s[255]="", t[25]="";
    fgets(s, 255, stdin);
    fgets(t, 25, stdin);
    for(int i=0;i<strlen(t);i++){
        if(t[i]=='\n'){
            t[i]='\0';
            break;
        }
    }
    char *j = strstr(s, t);
    if (j == NULL)
    {
        printf("0");
        return 0;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (j == &s[i])
        {
            printf("%d ", i);
            return 0;
        }
    }
    return 0;
}