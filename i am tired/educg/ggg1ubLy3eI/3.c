#include <stdio.h>

int main() {
    float s, t = 0.0, salary_after_tax;
    scanf("%f", &s);

    // 使用if-else结构确定税率
    switch ((int)s / 1000) {
        case 0:  // s < 1000
            t = 0.0;
            break;
        case 1:  // 1000 <= s < 2000
            t = 0.10;
            break;
        case 2:  // 2000 <= s < 3000
            t = 0.15;
            break;
        case 3:  // 3000 <= s < 4000
            t = 0.20;
            break;
        default: // s >= 4000
            t = 0.25;
            break;
    }

    // 计算税后工资
    salary_after_tax = s * (1 - t);

    // 输出税后工资，保留两位小数
    printf("%.2f", salary_after_tax);

    return 0;
}
