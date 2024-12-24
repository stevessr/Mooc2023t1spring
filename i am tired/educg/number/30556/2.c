// 小数形式与科学计数法转换（简）
#include <stdio.h>
#include <stdbool.h>

int main()
{
    char buff[255] = "0", result[255] = "0";
    fgets(buff, 255, stdin);
    bool point = false, start = false, havepoint = false;
    int element = 0, type = 0, j = 0;
    for (int i = 0; buff[i] != '\n'; i++)
    {
        if (buff[i] == '.')
        {
            point = true;
            if (!start)
            {
                type = -1;
                element = 1;
            }
            continue;
            ;
        }
        if (!(buff[i] <= '0' || buff[i] > '9' || start))
        {
            start = true;
            result[j++] = buff[i];
            if (!point)
            {
                type = 1;
            }
            continue;
        }
        if (start)
        {
            if (havepoint == false)
            {
                havepoint = true;
                result[j++] = '.';
            }
            result[j++] = buff[i];
        }
        if (type != 0)
        {
            if (start && (!point))
            {
                element++;
            }
            else if (point && (!start))
            {
                element++;
            }
        }
    }
    printf("%se%d", result, element * type);
    return 0;
}