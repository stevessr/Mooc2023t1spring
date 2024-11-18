#include <stdio.h>
#include <stdlib.h>

void process_route(int route_num, int N, int* satisfaction) {
    int max_sum = 0;  // 最大和
    int current_sum = 0;  // 当前和
    int start = 0, end = 0;  // 最佳子段的起始和结束位置
    int temp_start = 0;  // 临时起始位置

    // Kadane's algorithm
    for (int i = 0; i < N - 1; i++) {
        current_sum += satisfaction[i];

        if (current_sum > max_sum || (current_sum == max_sum && (i - temp_start > end - start))) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }

        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }

    if (max_sum > 0) {
        printf("The nicest part of route %d is between stops %d and %d\n", route_num, start + 1, end + 2);
    } else {
        printf("Route %d has no nice parts\n", route_num);
    }
}

int main() {
    int b;
    scanf("%d", &b);

    for (int route_num = 1; route_num <= b; route_num++) {
        int N;
        scanf("%d", &N);
        
        int* satisfaction = (int*)malloc((N - 1) * sizeof(int));

        for (int i = 0; i < N - 1; i++) {
            scanf("%d", &satisfaction[i]);
        }

        process_route(route_num, N, satisfaction);

        free(satisfaction);
    }

    return 0;
}
