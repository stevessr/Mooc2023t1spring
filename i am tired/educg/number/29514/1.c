#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Isort(int *S, int n)
{
    int temp[n], tocompare;
    temp[0] = S[0];
    for (int i = 1; i < n; i++)
    {
        tocompare = S[i];
        if (tocompare >= temp[i - 1])
        {
            temp[i] = tocompare;
        }
        else
        {
            for (int j = i; j >= 0; j--)
            {
                if (tocompare >= temp[j - 1] || j == 0)
                {
                    temp[j] = tocompare;
                    break;
                }
                else
                {
                    temp[j] = temp[j - 1];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        S[i] = temp[i];
    }
}

int IsortDrop(int *S, int n)
{
    int temp[n], tocompare;
    temp[0] = S[0];
    int j=1;
    for (int i = 1; i < n; i++)
    {
        tocompare = S[i];

        if (tocompare > temp[i - 1])
        {
            temp[j++] = tocompare;
        }
        else if (tocompare == temp[i - 1])
        {
            break;
        }
        else
        {
            for (int jp = j; jp >= 0; jp--)
            {
                if (tocompare > temp[jp - 1] || jp == 0)
                {
                    temp[jp] = tocompare;
                    break;
                }
                else
                {
                    temp[jp] = temp[jp - 1];
                }
            }
        }
    }
    for (int i = 0; i < j; i++)
    {
        S[i] = temp[i];
    }
    return j;
}

void merge(int S1[], int n1, int S2[], int n2, int target[])
{
    int i, j, k;
    i = j = k = 0;
    while (i < n1 && j < n2)
    {
        if (S1[i] <= S2[j])
        {
            target[k++] = S1[i++];
        }
        else
        {
            target[k++] = S2[j++];
        }
    }
    while (i < n1)
    {
        target[k++] = S1[i++];
    }
    while (j < n2)
    {
        target[k++] = S2[j++];
    }
}

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    int S1[A], S2[B];
    for (int i = 0; i < A; i++)
    {
        scanf("%d", &S1[i]);
    }
    for (int i = 0; i < B; i++)
    {
        scanf("%d", &S2[i]);
    }
    Isort(S1, A);
    Isort(S2, B);
    int C[A + B];
    merge(S1, A, S2, B, C);
    IsortDrop(C, A + B);
    printf("%d ", C[0]);
    for (int i = 1, last = C[0], current; i < A+B; i++)
    {
        current = C[i];
        if (current != last)
        {
            printf("%d ", C[i]);
        }
        last = current;
    }
    return 0;
}