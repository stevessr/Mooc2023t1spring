// 旋转矩阵
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int A[n][n], B[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]!=B[i][j]){
                i=j=n;
            }
        }
        if(i==(n-1)){
            printf("0");
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]!=B[n-i-1][n-j-1]){
                i=j=n;
            }
        }
        if(i==(n-1)){
            printf("180");
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]!=B[j][i]){
                i=j=n;
            }
        }
        if(i==(n-1)){
            printf("90");
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]!=B[n-j-1][n-i-1]){
                i=j=n;
            }
        }
        if(i==(n-1)){
            printf("270");
            return 0;
        }
    }
    printf("-1");
    return 0;
}