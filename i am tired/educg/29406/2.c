#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(const char *s1, char *s2)
{
    int i = 0, j = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0' && s1[i - 1] < s1[i + 1])
        {
            for (char ch = s1[i - 1] + 1; ch <= s1[i + 1]; ch++)
            {
                s2[j++] = ch;
            }
            i++;
        }
        else
        {
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0';
}

int main()
{
    char input[1000], output[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    expand(input, output);
    printf("%s\n", output);

    return 0;
}
