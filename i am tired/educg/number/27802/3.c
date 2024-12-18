#include <stdio.h>

int main() {
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;
    int age;
    scanf("%d.%d.%d", &birthYear, &birthMonth, &birthDay);
    scanf("%d.%d.%d", &currentYear, &currentMonth, &currentDay);

    // 计算基础年龄
    age = currentYear - birthYear;

    // 如果当前月小于出生月，或者当前月等于出生月但当前日小于出生日，则年龄减1
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }

    // 输出实际年龄
    printf("%d\n", age);

    return 0;
}
