#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static char skip[10][20] = {0};  // 用于存储已经处理过的函数名
static int nameamount = 0;        // 自定义函数的数量

// 判断函数名是否已经使用
bool isused(char *str)
{
    for (int i = 0; i < nameamount; i++)
    {
        if (strcmp(str, skip[i]) == 0)  // 比较函数名是否相同
        {
            return true;
        }
    }
    return false;
}

int main()
{
    FILE *fin = fopen("input.c", "r");
    FILE *fout = fopen("output.c", "w+");

    if (!fin || !fout) {
        printf("Error opening files.\n");
        return -1;
    }

    char buff[255], buffword[20], bufftemp[20];

    while (fscanf(fin, "%s", buff) != EOF)  // 读取输入文件
    {
        // 如果是预处理指令或库文件头文件，则直接写入输出文件
        if (buff[0] == '#' || buff[0] == '<')
        {
            fprintf(fout, "%s", buff);
        }
        else if (strcmp(buff, "int") == 0 || strcmp(buff, "double") == 0 ||
                 strcmp(buff, "void") == 0 || strcmp(buff, "char") == 0 ||
                 strcmp(buff, "long") == 0)
        {
            // 处理数据类型（如 int, char 等）
            fprintf(fout, "%s", buff);
            if (fscanf(fin, "%s", buff) != EOF)
            {
                // 如果遇到指针 *，则处理指针类型
                if (buff[0] == '*')
                {
                    fprintf(fout, "*");
                    if (buff[1] != 0)
                    {
                        // 处理指针类型的函数名
                        int i = 1;
                        while (buff[i] != 0)  // 字符串向前移动
                        {
                            buff[i - 1] = buff[i++];
                        }
                        if (!isused(buff))
                            strcpy(skip[nameamount++], buff);  // 记录自定义函数名
                    }
                    else
                    {
                        fscanf(fin, "%s", buffword);
                        fscanf(fin, "%s", bufftemp);
                        if (bufftemp[0] == '(')
                        {
                            // 保留函数参数部分
                            fprintf(fout, "%s", bufftemp);
                            if (!isused(buffword))
                                strcpy(skip[nameamount++], buffword);
                        }
                        else
                        {
                            // 输出带参数的函数名
                            fprintf(fout, "%s%s", buffword, bufftemp);
                        }
                    }
                }
                else
                {
                    fscanf(fin, "%s", bufftemp);
                    if (bufftemp[0] == '(')
                    {
                        // 如果是函数原型或调用，跳过函数名并保留参数
                        if (!isused(buff))
                            strcpy(skip[nameamount++], buff);

                        // 保持参数部分
                        fprintf(fout, "(");
                        do {
                            fprintf(fout, "%s", bufftemp);
                            fscanf(fin, "%s", bufftemp);
                        } while (bufftemp[0] != ')'); // 一直到结束的括号
                        fprintf(fout, "%s", bufftemp);
                    }
                    else
                    {
                        fprintf(fout, "%s%s", bufftemp, bufftemp);
                    }
                }
            }
            else
            {
                return 0;
            }
        }
        else if (isused(buff))  // 如果是自定义函数名，跳过
        {
            continue;
        }
        else
        {
            // 普通标识符（不是自定义函数名）直接输出
            if (strcmp(buff, ",") == 0)
            {
                // 保留逗号分隔符
                fprintf(fout, ",");
            }
            else
            {
                // 普通标识符（不是自定义函数名）直接输出
                fprintf(fout, "%s", buff);
            }
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
