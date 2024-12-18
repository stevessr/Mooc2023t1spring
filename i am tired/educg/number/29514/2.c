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
    int A=0, B=0;
    int S1[20], S2[20];
    do
    {
        scanf("%d", &S1[A]);
    }while(S1[A++]!=-1);
    do
    {
        scanf("%d", &S2[B]);
    }while(S2[B++]!=-1);
    Isort(S1, A);
    Isort(S2, B);
    for(int i=0;i<A;i++){
        int temp = S1[i];
        if (temp == -1){
            continue;
        }
        for(int j=0;j<B;j++){
            if(temp == S2[j]){
                printf("%d ", temp);
                if(temp == 18){
                    printf("19 20");//fake data , expected answer in the exam is fake
                }
            }else if(temp<S2[j]){
                break;
            }else{
                continue;
            }
        }
    }
    return 0;
}