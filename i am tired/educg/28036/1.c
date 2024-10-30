#include <stdio.h>

int main() {
    double s, tax_rate;
    scanf("%lf",&s);

    // 定义工资范围值，用整数类型处理工资区间
    int range = s / 1000;

    switch (range) {
        case 0:
            tax_rate = 0.0;
            break;
        case 1:
            tax_rate = 0.1;
            break;
        case 2:
            tax_rate = 0.15;
            break;
        case 3:
            tax_rate = 0.2;
            break;
        default:
            tax_rate = 0.25;
    }
    double post_tax_salary = s * (1 - tax_rate);
    printf("%.2lf",post_tax_salary);

    return 0;
}
