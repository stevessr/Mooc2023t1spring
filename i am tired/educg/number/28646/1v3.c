#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 1024
//暴力匹配 我累了
int main()
{
    FILE *inFile = fopen("in.h", "r");
    FILE *outFile = fopen("out.txt", "w");

    if (!inFile || !outFile)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, inFile) != NULL)
    {
        for (int i = 0; line[i] != ';'; i++)
        {
            if (line[i] == 'i')
            {
                if (line[i + 1] == 'n')
                {
                    if (line[i + 2] == 't')
                    {
                        fprintf(outFile, "int ");
                        i += 3;
                    }
                }
            }
            else if (line[i] == 's')
            {
                if (line[i + 1] == 'h')
                {
                    if (line[i + 2] == 'o')
                    {
                        if (line[i + 3] == 'r')
                        {
                            if (line[i + 4] == 't')
                            {
                                fprintf(outFile, "short ");
                                i += 5;
                            }
                        }
                    }
                }
            }
            else if (line[i] == 'l')
            {
                if (line[i + 1] == 'o')
                {
                    if (line[i + 2] == 'n')
                    {
                        if (line[i + 3] == 'g')
                        {
                            fprintf(outFile, "long ");
                            i += 4;
                        }
                    }
                }
            }
            else if (line[i] == 'c')
            {
                if (line[i + 1] == 'h')
                {
                    if (line[i + 2] == 'a')
                    {
                        if (line[i + 3] == 'r')
                        {
                            fprintf(outFile, "char ");
                            i += 4;
                        }
                    }
                }
            }
            else if (line[i] == 'v')
            {
                if (line[i + 1] == 'o')
                {
                    if (line[i + 2] == 'i')
                    {
                        if (line[i + 3] == 'd')
                        {
                            fprintf(outFile, "void ");
                            i += 4;
                        }
                    }
                }
            }
            else if (line[i] == 'f')
            {
                if (line[i + 1] == 'l')
                {
                    if (line[i + 2] == 'o')
                    {
                        if (line[i + 3] == 'a')
                        {
                            if (line[i + 4] == 't')
                            {
                                fprintf(outFile, "float ");
                                i += 5;
                            }
                        }
                    }
                }
            }
            else if (line[i] == 'd')
            {
                if (line[i + 1] == 'o')
                {
                    if (line[i + 2] == 'u')
                    {
                        if (line[i + 3] == 'b')
                        {
                            if (line[i + 4] == 'l')
                            {
                                if (line[i + 5] == 'e')
                                {
                                    fprintf(outFile, "double ");
                                    i += 6;
                                }
                            }
                        }
                    }
                }
            }
        }
        fprintf(outFile, "\n");
    }

    fclose(inFile);
    fclose(outFile);

    return EXIT_SUCCESS;
}