// 单词排序
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAXWORD = 200;
const int MAXWORDSIZE = 200;

int cmp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main()
{
    FILE *fin = fopen("sort.in", "r");
    FILE *fout = fopen("sort.out", "w");
    char *words[MAXWORD];
    char *word = NULL;
    char temp[MAXWORDSIZE];
    int i = 0;
    bool jumper = false;
    while (fscanf(fin, "%s", temp) != EOF)
    {

        jumper = false;
        for (int j = 0; j < i; j++)
        {
            if (strcmp((words[j]), temp) == 0)
            {
                jumper = true;
                break;
            }
        }
        if (!jumper)
        {
            word = malloc(sizeof(temp) + 1);
            strcpy(word, temp);
            words[i] = word;
            i++;
        }
    }

    qsort(words, i, sizeof(char *), cmp);

    for (int j = 0; j < i; j++)
    {
        if (j != 0)
        {
            fprintf(fout, " ");
        }
        fprintf(fout, "%s", (words[j]));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

