#include <stdio.h>
int main(){
    int spaces = 0, tabs = 0, newlines = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            spaces++;
        } else if (ch == '\t') {
            tabs++;
        } else if (ch == '\n') {
            newlines++;
        }
    }
    printf("%d %d %d\n", spaces, tabs, newlines-1);

    return 0;
}