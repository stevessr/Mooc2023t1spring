#include <stdio.h>

int main() {
    char ch;
    int spaceCount = 0, newlineCount = 0;

    // 使用 getchar() 循环读取每个字符直到 EOF
    while ((ch = getchar()) != EOF) {
        if (ch == ' ')
            spaceCount++;
        else if (ch == '\n')
            newlineCount++;
    }

    // 输出空格和换行符的数量，之间用空格隔开
    printf("%d %d", spaceCount, newlineCount);

    return 0;
}
