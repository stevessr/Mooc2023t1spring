#include <stdio.h>

int main() {
    short mount;
    long max, min, temp;

    // 从键盘输入数量和第一个数
    scanf("%hd %ld", &mount, &temp);
    
    // 初始化最大值和最小值
    min = max = temp;
    
    // 进入循环处理剩余的数
    while (--mount > 0) {
        scanf("%ld", &temp);
        
        if (temp > max) {
            max = temp;
        } else if (temp < min) {
            min = temp;
        }
    }

    // 输出最大值和最小值 (可以根据需求添加)
    printf("%ld %ld", max, min);

    return 0;
}
