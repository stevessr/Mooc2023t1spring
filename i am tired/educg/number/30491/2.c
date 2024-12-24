// 从字符串中删除字符（新）
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int cmp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int main()
{
    char strA[52], strB[52], result[52]="";
    scanf("%s\n%s", strA, strB);
    int p = 0;
    for (int i = 0; strA[i] != '\0'; i++)
    {
        bool found;
        found = false;
        for (int j = 0; strB[j] != '\0'; j++)
        {
            if (strA[i] == strB[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            result[p++] = strA[i];
        }
    }
    if(p==0){
        printf("Empty");
        return 0;
    }
    result[p] = '\0';
    qsort(result,p,sizeof(char),cmp);
    printf("%s",result);
    return 0;
}