#include <stdio.h>
#include <stdbool.h>
int main()
{
    int a, b;
    scanf("%d", &a);
    int ag[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &ag[i]);
    }
    scanf("%d", &b);
    int bg[b];
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &bg[i]);
    }
    bool ok = false;
    for (int i = 0; i < a; i++)
    {
        bool same = false;
        for (int j = 0; j < b; j++)
        {
            if (ag[i] == bg[j])
            {
                same = true;
                break;
            }
        }
        for (int j = i - 1; j > -1; j--)
        {
            if (ag[j] == ag[i])
            {
                same = false;
                break;
            }
        }
        if (same)
        {
            printf("%d ", ag[i]);
            ok = true;
        }
    }
    if(ok == false){
        printf("No Answer");
    }
    return 0;
}