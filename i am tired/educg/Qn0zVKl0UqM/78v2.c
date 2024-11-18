#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse_format(const char *fmt, int *left_align, int *width, int *precision) {
    *left_align = 0;
    *width = 0;
    *precision = 10; // 默认精度为10

    const char *p = fmt;

    // 检查左对齐标志
    if (*p == '-') {
        *left_align = 1;
        p++;
    }

    // 解析宽度
    while (*p >= '0' && *p <= '9') {
        *width = *width * 10 + (*p - '0');
        p++;
    }

    // 解析精度
    if (*p == '.') {
        *precision = 0;
        p++;
        while (*p >= '0' && *p <= '9') {
            *precision = *precision * 10 + (*p - '0');
            p++;
        }
    }
}

void format_output(double value, int left_align, int width, int precision) {
    char buffer[101]; // 存储格式化后的浮点数
    char format[20];  // 构造的格式控制字符串

    // 构造格式控制字符串
    sprintf(format, "%%.%df", precision);
    sprintf(buffer, format, value);

    int actual_length = strlen(buffer);
    int padding = (width > actual_length) ? width - actual_length : 0;

    // 输出格式化结果
    if (left_align) {
        printf("%s", buffer);
        for (int i = 0; i < padding; i++) {
            putchar('*');
        }
    } else {
        for (int i = 0; i < padding; i++) {
            putchar('*');
        }
        printf("%s", buffer);
    }
    putchar('\n');
}

int main() {
    double value;
    char format_str[30];
    FILE *fp = fopen("in.txt", "r");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    // 读取浮点数和格式控制字符串
    fscanf(fp, "%lf", &value);
    fscanf(fp, "%s", format_str);
    fclose(fp);

    // 解析格式控制字符串
    int left_align, width, precision;
    parse_format(format_str, &left_align, &width, &precision);

    // 输出格式化的结果
    format_output(value, left_align, width, precision);

    return 0;
}
