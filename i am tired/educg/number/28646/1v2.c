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
    
    char buffer[256];
    while (fscanf(inputFile, "%255s", buffer) != EOF) {
        // 检查是否包含任何关键字
        for (int i = 0; i < numKeywords; i++) {
            if (strstr(buffer, keywords[i]) != NULL) {
                fprintf(outputFile, "%s\n", keywords[i]);
                break;
            }
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
