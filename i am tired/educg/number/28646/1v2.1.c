#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findKeywords(const char *filename) {
    FILE *inputFile = fopen(filename, "r");
    FILE *outputFile = fopen("out.txt", "w");
    
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
    int foundKeyword; 

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        foundKeyword = 0;
        for (int i = 0; i < numKeywords; i++) {
            char *pos = line;
            while ((pos = strstr(pos, keywords[i])) != NULL) {
                if (foundKeyword) {
                    fprintf(outputFile, " ");
                }
                fprintf(outputFile, "%s", keywords[i]);
                foundKeyword = 1;
                pos += strlen(keywords[i]);
            }
        }
        if (foundKeyword) {
            fprintf(outputFile, "\n");
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    findKeywords("in.h");
    printf("Keywords have been written to out.txt\n");
    return 0;
}
