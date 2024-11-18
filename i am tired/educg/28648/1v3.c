#include <stdio.h>
#include <string.h>
#include <stdbool.h>
static char skip[10][20] = {0};
static int nameamount = 0;
bool isused(char *str)
{
    if (strcmp(str, "main") == 0)
    {
        return false;
    }
    for (int i = 0; i < nameamount; i++)
    {
        if (strcmp(str, skip[i]) == 0)
        {
            return true;
        }
    }
    return false;
}
bool is_standard_lib_function(const char *str)
{
    const char *standard_functions[] = {"printf", "scanf", "fopen", "fclose", "fscanf"};
    for (int i = 0; i < sizeof(standard_functions) / sizeof(standard_functions[0]); i++)
    {
        if (strcmp(str, standard_functions[i]) == 0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    FILE *fin = fopen("input.c", "r");
    FILE *fout = fopen("output.c", "w");
    if (!fin || !fout)
    {
        printf("Error opening files.\n");
        return -1;
    }
    char buff[255], buffword[20], bufftemp[20];
    while (fscanf(fin, "%s", buff) != EOF)
    {
        if (strcmp(buff, "int") == 0 || strcmp(buff, "double") == 0 ||
            strcmp(buff, "void") == 0 || strcmp(buff, "char") == 0 ||
            strcmp(buff, "long") == 0)
        {
            if (fscanf(fin, "%s", buffword) != EOF && fscanf(fin, "%s", bufftemp) != EOF)
            {
                if (bufftemp[0] == '(')
                {
                    if (!isused(buffword))
                    {
                        strcpy(skip[nameamount++], buffword);
                    }
                }
            }
        }
    }
    rewind(fin);
    while (fscanf(fin, "%s", buff) != EOF)
    {
        if (buff[0] == ' ' || buff[0] == '\t' || buff[0] == '\n')
        {
            continue;
        }
        if (isused(buff))
        {
            continue;
        }
        if (is_standard_lib_function(buff))
        {
            fprintf(fout, "%s", buff);
            continue;
        }
        fprintf(fout, "%s", buff);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
