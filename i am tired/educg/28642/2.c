#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char *insert(char *string, char c);
int main()
{
    char str[51] = {0}, ch;
    fgets(str, sizeof(str), stdin);
    scanf("%c", &ch);
    char *result = insert(str, ch);
    printf("%s", result);
    return 0;
}
char *insert(char *string, char c)
{
    int len = strlen(string);
    static char result[51];
    int i = 0, j = 0;
    while (i < len && string[i] < c)
    {
        if(string[i] != '\n')result[j++] = string[i++];
        else i++;

    }
    result[j++] = c;
    while (i < len)
    {
        result[j++] = string[i++];
    }
    result[j] = '\0';
    return result;
}
