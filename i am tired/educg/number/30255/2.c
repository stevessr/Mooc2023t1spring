#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fin = fopen("check.in", "r"), *fout = fopen("check.out", "w");
    int number[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // "{","}","(",")" ,"<",">","[","]"
    char temp=2;
    while (fscanf(fin, "%c", &temp) != EOF)
    {
        switch (temp)
        {
        case '{':
            number[0]++;
            break;
        case '}':
            number[1]++;
            break;
        case '(':
            number[2]++;
            break;
        case ')':
            number[3]++;
            break;
        case '<':
            number[4]++;
            break;
        case '>':
            number[5]++;
            break;
        case '[':
            number[6]++;
            break;
        case ']':
            number[7]++;
            break;
        default:
            break;
        }
    }
    if (number[0] == number[1] 
    && number[2] == number[3] 
    //&& number[4] == number[5] 
    && number[6] == number[7])
    {
        fprintf(fout, "True");
    }
    else
    {
        fprintf(fout, "False");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}