#include <stdio.h>
#include <string.h>

int main() {
    char str[1000], tok[100];
    
    // 输入字符串
    fgets(str, sizeof(str), stdin);
    fgets(tok, sizeof(tok), stdin);
    
    // 去掉fgets()捕获的换行符
    str[strcspn(str, "\n")] = '\0';
    tok[strcspn(tok, "\n")] = '\0';

    // 使用strtok逐个输出被分割的字符串
    char *token = strtok(str, tok);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, tok);
    }

    return 0;
}
