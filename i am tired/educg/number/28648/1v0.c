

共享


您说：
#include <stdio.h>
#include <string.h>
#include <fileapi.h>
#include <stdbool.h>
static char skip[10][20]={0};
static int nameamount =0;
bool isused(char *str)
{
    for (int i = 0; i < nameamount; i++)
    {
        if (strcmp(str, skip[i]))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    FILE *fin = fopen("input.c", "r"), *fout = fopen("output.c", "w+");
    static char buff[255], buffword[20], bufftemp[20];// skip[10][20] = {0};
    // bool tojump = false;
    //static int nameamount = 0;
    while (fscanf(fin, "%s", buff))
    {
        if (buff[0] == '#' || buff[0] == '<')
        {
            fprintf(fout, "%s", buff);
        }
        else if (strcmp(buff, "int") || strcmp(buff, "double") || strcmp(buff, "void") || strcmp(buff, "char") || strcmp(buff, "long"))
        {
            fprintf(fout, "%s", buff);
            if (fscanf(fin, "%s", buff))
            {
                if (buff[0] == '*')
                {
                    fprintf(fout, "*");
                    if (buff[1] != 0)
                    {
                        int i = 1;
                        for (; buff[i] != 0; buff[i - 1] = buff[i++])
                        {
                        }
                        if (!isused(buff))
                            strcpy(skip[nameamount++], buff);
                    }
                    else
                    {
                        fscanf(fin, "%s", buffword);
                        fscanf(fin, "%s", bufftemp);
                        if (bufftemp[0] == '(')
                        {
                            fprintf(fout, "%s", bufftemp);
                            if (!isused(buffword))
                                strcpy(skip[nameamount++], buffword);
                        }
                        else
                        {
                            fprintf(fout, "%s%s", buffword, bufftemp);
                        }
                    }
                }
                else
                {
                    fscanf(fin, "%s", bufftemp);
                    if (bufftemp[0] == '(')
                    {
                        if (!isused(buff))
                            strcpy(skip[nameamount++], buff);
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
        else if (isused(buff))
        {
            continue;
        }
        else
        {
            fprintf(fout, "%s", buff);
        }
    }
    return 0;
}