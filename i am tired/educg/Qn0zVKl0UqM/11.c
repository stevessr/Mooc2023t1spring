#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int left, right;
} Period;
int compare(const void *a, const void *b) {
    Period *p1 = (Period *)a;
    Period *p2 = (Period *)b;
    if (p1->left == p2->left)
        return p1->right - p2->right;
    return p1->left - p2->left;
}
int mergePeriods(Period *periods, int n, Period *merged) {
    qsort(periods, n, sizeof(Period), compare);
    int count = 0;
    merged[count++] = periods[0];

    for (int i = 1; i < n; ++i) {
        if (merged[count - 1].right < periods[i].left) {
            merged[count++] = periods[i];
        } else {
            if (merged[count - 1].right < periods[i].right) {
                merged[count - 1].right = periods[i].right;
            }
        }
    }
    return count;
}
int main() {
    FILE *input = fopen("prz.in", "r");
    FILE *output = fopen("prz.out", "w");
    
    int n;
    fscanf(input, "%d", &n);
    
    Period *periods = (Period *)malloc(n * sizeof(Period));
    Period *merged = (Period *)malloc(n * sizeof(Period));
    
    for (int i = 0; i < n; ++i) {
        fscanf(input, "%d %d", &periods[i].left, &periods[i].right);
    }
    int mergedCount = mergePeriods(periods, n, merged);
    for (int i = 0; i < mergedCount; ++i) {
        fprintf(output, "%d %d\n", merged[i].left, merged[i].right);
    }
    free(periods);
    free(merged);
    fclose(input);
    fclose(output);
    return 0;
}
