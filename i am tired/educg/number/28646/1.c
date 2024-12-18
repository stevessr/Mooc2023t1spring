#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to find the last space before a specific character and terminate the string there
void truncate_last_word_before(char *start, char *end) {
    // Start from the character before `end` and move backward to find a space
    while (end > start && !isspace(*(end - 1))) {
        end--;
    }
    *end = '\0';  // Truncate at the found position
}

void extract_and_write(FILE *inFile, FILE *outFile) {
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, MAX_LINE_LENGTH, inFile) != NULL) {
        char *leftBracketPos = strchr(line, '(');  // Find the left bracket
        if (leftBracketPos) {
            *leftBracketPos = '\0';  // Terminate string to get text before '('
            
            // Truncate last word before '(' if there is one
            truncate_last_word_before(line, leftBracketPos);
            fprintf(outFile, "%s", line);  // Write the truncated text before '('
            
            char *remaining = leftBracketPos + 1;  // Move to text after '('
            char *commaOrRightBracketPos = strpbrk(remaining, ",)");  // Find ',' or ')'
            if (commaOrRightBracketPos) {
                *commaOrRightBracketPos = '\0';  // Terminate string to get text before ',' or ')'
                
                // Truncate last word before ',' or ')' if there is one
                truncate_last_word_before(remaining, commaOrRightBracketPos);
                fprintf(outFile, "%s", remaining);  // Write the truncated text
            }
        }
        fprintf(outFile, "\n");  // New line after processing each line
    }
}

int main() {
    FILE *inFile = fopen("in.h", "r");
    FILE *outFile = fopen("out.txt", "w");

    if (!inFile || !outFile) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    extract_and_write(inFile, outFile);

    fclose(inFile);
    fclose(outFile);
    
    return EXIT_SUCCESS;
}
