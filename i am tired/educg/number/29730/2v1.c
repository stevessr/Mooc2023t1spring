#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// 比较函数，用于qsort排序
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// 去除重复的单词
int remove_duplicates(char *words[], int word_count) {
    int unique_count = 0;
    for (int i = 0; i < word_count; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            words[unique_count++] = words[i];
        }
    }
    return unique_count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // 打开源文件
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // 读取单词
    char *words[MAX_WORDS];
    int word_count = 0;

    // 分配内存并读取单词
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", buffer) == 1) {
        words[word_count] = (char *)malloc(strlen(buffer) + 1);
        if (words[word_count] == NULL) {
            perror("Memory allocation error");
            return 1;
        }
        strcpy(words[word_count], buffer);
        word_count++;
        if (word_count >= MAX_WORDS) {
            break;
        }
    }
    fclose(input_file);

    // 排序单词
    qsort(words, word_count, sizeof(char *), compare);

    // 去重
    int unique_count = remove_duplicates(words, word_count);

    // 打开输出文件
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // 输出去重后、排序后的单词
    for (int i = 0; i < unique_count; i++) {
        fprintf(output_file, "%s ", words[i]);
        free(words[i]);  // 释放内存
    }

    fclose(output_file);

    printf("Words have been sorted and unique words are written to the output file.\n");

    return 0;
}
