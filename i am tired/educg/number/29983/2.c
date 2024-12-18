#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* av = NULL;
    int av_size = 0, temp;

    // 输入第一个集合
    while (1)
    {
        scanf("%d", &temp);
        if (temp == -1)
        {
            break;
        }
        av = (int*)realloc(av, (av_size + 1) * sizeof(int));
        av[av_size++] = temp;
    }

    // 输入第二个集合并用数组存储
    int* bs = NULL;
    int bs_size = 0;

    while (1)
    {
        scanf("%d", &temp);
        if (temp == -1)
        {
            break;
        }
        bs = (int*)realloc(bs, (bs_size + 1) * sizeof(int));
        bs[bs_size++] = temp;
    }

    // 求差集
    for (int i = 0; i < av_size; i++)
    {
        int found = 0;
        for (int j = 0; j < bs_size; j++)
        {
            if (av[i] == bs[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("%d ", av[i]);
        }
    }

    // 释放动态分配的内存
    free(av);
    free(bs);

    return 0;
}
