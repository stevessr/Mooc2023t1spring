#include <stdio.h>
#include <string.h>
void str_bin(char* str1, char* str2) {
    int i = 0, j = 0, k = 0;
    char result[201];
    while (str1[i] != '\0' && str2[j] != '\0') {
        if (str1[i] < str2[j]) {
            result[k++] = str1[i++];
        } else if (str1[i] > str2[j]) {
            result[k++] = str2[j++];
        } else {
            result[k++] = str1[i++];
            j++;
        }
    }
    while (str1[i] != '\0') {
        result[k++] = str1[i++];
    }
    while (str2[j] != '\0') {
        result[k++] = str2[j++];
    }
    result[k] = '\0';
    strcpy(str1, result);
}

int main() {
    char str1[101], str2[101];
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    str_bin(str1, str2);
    printf("%s\n", str1);
    return 0;
}