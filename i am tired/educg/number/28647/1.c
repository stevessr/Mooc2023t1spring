#include <stdio.h>
#include <string.h>
char *del(char *s);
int main()
{
    char str[400];
    scanf("%s", &str);
    // size_t sl = strlen(str);
    char *todo = del(str);
    for(int i=strlen(todo)-1;i>=0;i--){
        printf("%c",todo[i]);
    }
    return 0;
}
char *del(char *stri)
{
    static char temp[400];
    char ch, ch2;
    size_t sl = strlen(stri);
    for (int i = sl - 1, j = 0; i >= 0; i--)
    {
        ch = ch2 = stri[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 'a' - 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch += 'A' - 'a';
        }
        if (strchr(temp, ch) == NULL && strchr(temp, ch2) == NULL)
        {
            temp[j++] = stri[i];
            // printf("%c", stri[i]);
        }
    }
    return temp;
}