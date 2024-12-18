#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

// 检查是否是目标类型
int is_target_type(const char *word) {
    const char *target_types[] = {"int", "char", "double", "float", "long", "void"};
    for (int i = 0; i < 6; i++) {
        if (strcmp(word, target_types[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// 处理单个函数原型，提取类型并写入结果文件
void process_prototype(const char *prototype, FILE *outfile) {
    char word[MAX_LINE_LENGTH];
    int i = 0, j = 0;
    int in_type_section = 1;  // 标记是否在返回类型和函数名部分
    int found_type = 0;       // 标记是否找到类型关键字

    while (prototype[i] != '\0') {
        // 跳过空白字符
        while (isspace(prototype[i])) i++;

        // 识别一个单词的开始
        if (isalpha(prototype[i])) {
            j = 0;
            // 提取单词
            while (isalpha(prototype[i])) {
                word[j++] = prototype[i++];
            }
            word[j] = '\0';

            // 检查是否为有效类型关键字
            if (is_target_type(word) && in_type_section) {
                fprintf(outfile, "%s ", word);
                found_type = 1;
            } else if (!is_target_type(word)) {
                in_type_section = 0;  // 进入参数部分
            }
        }

        // 检查参数部分的开始，忽略函数名后可能的空格
        if (prototype[i] == '(') {
            in_type_section = 0;
            i++;
            while (prototype[i] != ')' && prototype[i] != '\0') {
                // 跳过空白字符
                while (isspace(prototype[i])) i++;

                if (isalpha(prototype[i])) {
                    j = 0;
                    // 提取参数类型关键字
                    while (isalpha(prototype[i])) {
                        word[j++] = prototype[i++];
                    }

                    // 检查指针符号
                    while (prototype[i] == '*') {
                        word[j++] = prototype[i++];
                    }
                    word[j] = '\0';

                    if (is_target_type(word)) {
                        fprintf(outfile, "%s ", word);
                    }
                }
                i++;
            }
        }
        i++;
    }

    if (found_type) {
        fprintf(outfile, "\n");
    }
}

int main() {
    FILE *infile = fopen("in.h", "r");
    FILE *outfile = fopen("out.txt", "w");
    char line[MAX_LINE_LENGTH];
    char prototype[MAX_LINE_LENGTH * 10];  // 用于存储完整函数原型
    int proto_index = 0;

    if (!infile || !outfile) {
        printf("无法打开文件。\n");
        return 1;
    }

    // 逐行读取并处理文件
    while (fgets(line, MAX_LINE_LENGTH, infile)) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            // 收集字符直到遇到分号
            if (line[i] != ';') {
                prototype[proto_index++] = line[i];
            } else {
                prototype[proto_index] = '\0';
                process_prototype(prototype, outfile);
                proto_index = 0;  // 重置原型缓冲区
            }
        }
    }

    fclose(infile);
    fclose(outfile);

    printf("处理完成，结果已写入out.txt文件。\n");
    return 0;
}
