#include <stdio.h>
#include <stdbool.h>
bool isNarcissistic(int a) {
    int hundreds = a / 100;         // 百位数
    int tens = (a / 10) % 10;       // 十位数
    int units = a % 10;             // 个位数
    return a == (hundreds * hundreds * hundreds +
                 tens * tens * tens +
                 units * units * units);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 100; i <= T; i++) {
        if (isNarcissistic(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
