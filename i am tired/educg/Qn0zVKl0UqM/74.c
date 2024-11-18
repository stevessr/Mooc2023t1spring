#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
bool isCharacter(char ch) {
    return isalnum(ch) || ch == '_';
}
bool isKeyword(const char* line, int start, const char* keyword) {
    int len = strlen(keyword);
    int end = start + len;
    if (strncmp(&line[start], keyword, len) == 0) {
        return (start == 0 || !isCharacter(line[start - 1])) &&
               (!isCharacter(line[end]));
    }
    return false;
}

int main() {
    FILE* file = fopen("in.c", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        row++;
        int len = strlen(line);
        bool skip = false;

        for (int i = 0; i < len; i++) {
            if (!isCharacter(line[i])) {
                if (line[i] == '/' && i + 1 < len && line[i + 1] == '/') {
                    skip = true;
                    break;
                }
                if (line[i] == '/' && i + 1 < len && line[i + 1] == '*') {
                    i += 2;
                    while (true) {
                        if (i >= len) {
                            if (!fgets(line, sizeof(line), file)) {
                                break;
                            }
                            len = strlen(line);
                            row++;
                            i = 0;
                        }
                        if (line[i] == '*' && i + 1 < len && line[i + 1] == '/') {
                            i++;
                            break;
                        }
                        i++;
                    }
                    continue;
                }
                if (line[i] == '"') {
                    i++;
                    while (i < len && line[i] != '"') {
                        if (line[i] == '\\' && i + 1 < len) i++;
                        i++;
                    }
                }
            }
            if (skip) break;
            if (isKeyword(line, i, "while")) {
                printf("while:%d,%d\n", row, i + 1);
                i += 4;
            } else if (isKeyword(line, i, "for")) {
                printf("for:%d,%d\n", row, i + 1);
                i += 2;
            } else if (isKeyword(line, i, "if")) {
                printf("if:%d,%d\n", row, i + 1);
                i += 1;
            }
        }
    }

    fclose(file);
    return 0;
}
