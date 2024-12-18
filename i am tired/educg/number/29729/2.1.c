#include <stdio.h>
#include <string.h>

int main()
{
    char s[255] = "", t[25] = "";
    fgets(s, 255, stdin); // 输入字符串 s
    fgets(t, 25, stdin);  // 输入子串 t

    // 去掉 t 字符串中的换行符
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] == '\n')
        {
            t[i] = '\0';
            break;
        }
    }

    // 查找子串 t 在字符串 s 中的首次出现
    char *j = strstr(s, t);
    if (j == NULL)
    {
        printf("0");
        return 0;
    }
    char *next = j;
    while (next != NULL)
    {
        j = next;
        next = strstr(j + 1, t);
    }

    // 输出子串的起始位置（第一个匹配位置）
    //printf("%s\n", j);
    printf("%ld", j - s); // 使用指针差计算位置
    return 0;
}
