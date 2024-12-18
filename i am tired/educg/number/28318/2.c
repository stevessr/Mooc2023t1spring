#include <stdio.h>

int main() {
    short a, b;
    scanf("%hd %hd", &a, &b); // 使用scanf获取输入
    for (int i = a; i <= b; i++) {
        if (i < 10) {
            if (i * i % 10 == i) {
                printf("%d\n", i); // 输出符合条件的数字
            }
        } else {
            if (i * i % 100 == i) {
                printf("%d\n", i); // 输出符合条件的数字
            }
        }
    }
    
    return 0;
}
