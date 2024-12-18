#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    const char *keywords[] = {"int", "float", "char", "void", "double", "long"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    char line[512];
    int foundKeyword;  // 用于跟踪一行中是否找到关键字

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        foundKeyword = 0; // 每行重置标记

        // 对当前行中每个关键字进行检查
        for (int i = 0; i < numKeywords; i++) {
            char *pos = line;
            // 循环查找每个关键字在该行中出现的所有位置
            while ((pos = strstr(pos, keywords[i])) != NULL) {
                if (foundKeyword) {
                    fprintf(outputFile, " ");  // 关键字间用空格分隔
                }
                fprintf(outputFile, "%s", keywords[i]);
                foundKeyword = 1;
                pos += strlen(keywords[i]); // 移动指针以继续查找
            }
        }

        // 如果在这一行找到关键字，才换行
        if (foundKeyword) {
            fprintf(outputFile, "\n");
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
