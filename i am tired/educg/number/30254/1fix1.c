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

    if (!fin || !fout)
    {
        fprintf(stderr, "Error: Could not open input or output file.\n");
        return 1;
    }

    char *words[MAXWORD];
    char temp[MAXWORDSIZE];
    int i = 0;

    while (fscanf(fin, "%s", temp) != EOF) // Limit input to prevent buffer overflow
    {
        if (i >= MAXWORD)
        {
            fprintf(stderr, "Error: Too many words. Maximum allowed is %d.\n", MAXWORD);
            break;
        }

        bool exists = false;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(words[j], temp) == 0)
            {
                exists = true;
                break;
            }
        }

        if (!exists)
        {
            char *word = malloc(strlen(temp) + 1); // Allocate exact memory for the word
            if (!word)
            {
                fprintf(stderr, "Error: Memory allocation failed.\n");
                for (int k = 0; k < i; k++)
                {
                    free(words[k]);
                }
                fclose(fin);
                fclose(fout);
                return 1;
            }

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
        fprintf(fout, "%s", words[j]);
        free(words[j]); // Free memory after use
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
