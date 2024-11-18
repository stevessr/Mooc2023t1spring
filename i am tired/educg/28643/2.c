#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main()
{
    char str[300], target[20];
    
    // 使用 fgets 正确获取字符串输入
    fgets(str, sizeof(str), stdin);
    fgets(target, sizeof(target), stdin);
    
    // 去除 fgets 可能留下的换行符
    str[strcspn(str, "\n")] = '\0';
    target[strcspn(target, "\n")] = '\0';
    
    int result = strrindex(str, target);
    printf("%d\n", result);
    
    return 0;
}

int strrindex(char s[], char t[])
{
    int sl = strlen(s); // 获取字符串 s 的长度
    int tl = strlen(t); // 获取字符串 t 的长度
    int try = -1;

    // 从右往左遍历 s，寻找 t
    for (int i = sl - tl; i >= 0; i--)
    {
        int j = 0;
        while (j < tl && s[i + j] == t[j])
        {
            j++;
        }
        if (j == tl) // 完全匹配
        {
            try = i;
            break;
        }
    }

    return try;
}
