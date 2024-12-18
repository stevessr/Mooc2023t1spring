// 单词排序
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int MAXWORD = 200;
const int MAXWORDSIZE = 200;
int cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}
//int main(int args, char *argv[])
int main()
{
    FILE *fin = fopen("sort.in", "r"), *fout = fopen("sort.out", "r");
    char *words[MAXWORD];
    char *word = NULL;
    char temp[MAXWORDSIZE];
    int i = 0;
    bool jumper = false;
    while (fscanf(fin, "%s", temp) != EOF)
    {
        word = (char *)(malloc(sizeof(temp)));
        jumper = false;
        for (int j = 0; j < i; j++)
        {
            if (strcmp((words[j]), temp) == 0)
            {
                free(word);
                jumper = true;
                break;
            }
        }
        if (!jumper)
        {
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
        fprintf(fout, "%s", (words[i]));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}