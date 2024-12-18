//求两个字符串的有序拼接后的字符串
#include <stdio.h>
#include <string.h>
int main()
{
    char buff1[255]="", buff2[255]="", buff3[255]="";
    fgets(buff1, 255, stdin);
    fgets(buff2, 255, stdin);
    int i, j, p;
    for (i = 0, j = 0, p = 0; buff1[i] != '\n' && buff2[j] != '\n';)
    {
        if (buff1[i] < buff2[j])
        {
            buff3[p++] = buff1[i++];
        }
        else if (buff1[i] > buff2[j])
        {
            buff3[p++] = buff2[j++];
        }
        else if (buff1[i] == buff2[j])
        {
            buff3[p++] = buff1[i++], j++;
        }
    }
    while (buff1[i] != '\n')
    {
        buff3[p++] = buff1[i++];
    }
    while (buff2[j] != '\n')
    {
        buff3[p++] = buff2[j++];
    }
    printf("%s", buff3);
    return 0;
}