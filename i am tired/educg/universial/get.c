#include <stdio.h>
int main(){
    char buff[256];
    char s='s';
    while (scanf("%c",&s) && s != EOF)
    {
        printf("%s",s);
    }
    return 0;
}