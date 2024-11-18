#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void findKeywords(const char *filename) {
    FILE *inputFile = fopen(filename, "r");
    FILE *outputFile = fopen("output.txt", "w");
    
    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }
    
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    // 定义关键字列表
    const char *keywords[] = {"int", "float", "char", "void", "double", "long"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    
    char line[512];
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char *token;
        int foundKeyword = 0;
        char returnType[50]; // 保存返回值类型
        char paramTypes[512] = ""; // 保存参数类型

        // 分割一行的单词，逐个检查
        token = strtok(line, " ,();\n");
        while (token != NULL) {
            // 检查是否是关键字
            for (int i = 0; i < numKeywords; i++) {
                if (strcmp(token, keywords[i]) == 0) {
                    if (foundKeyword == 0) {
                        // 第一个找到的关键字作为返回类型
                        strcpy(returnType, token);
                        foundKeyword = 1;
                    } else {
                        // 其他关键字作为参数类型
                        if (strlen(paramTypes) > 0) {
                            strcat(paramTypes, " ");  // 关键字之间加空格
                        }
                        // 处理指针符号，将指针符号 * 去掉
                        char param[50];
                        strncpy(param, token, sizeof(param) - 1);
                        param[sizeof(param) - 1] = '\0';
                        char *asterisk = strchr(param, '*');
                        if (asterisk != NULL) {
                            *asterisk = '\0';  // 去掉指针符号 *
                        }
                        strcat(paramTypes, param);
                    }
                    break;
                }
            }
            token = strtok(NULL, " ,();\n");
        }

        // 如果找到了返回类型和参数类型，输出到文件
        if (foundKeyword) {
            fprintf(outputFile, "%s %s\n", returnType, paramTypes);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    findKeywords("in.h");
    printf("Keywords have been written to output.txt\n");
    return 0;
}
