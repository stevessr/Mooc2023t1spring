#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// 结构体来保存 cos(x) 值和迭代次数
typedef struct
{
    double value;
    long count;
} Result;

// 修改 cosx 函数来返回结构体
Result cosx(double value, double x, long times, bool alpha, double target)
{
     double term = pow(x, 2 * times) / tgamma(2 * times + 1);

    // 递归终止条件
    if (term < target)
    {
        // 更新最后一次项
        value = alpha ? (value - term) : (value + term);
        Result res = {value, times};
        return res;
    }
    else
    {
        return cosx(alpha ? (value - term) : (value + term), x, times + 1, !alpha, target);
    }
}

int main()
{
    double x, T;
    scanf("%lf %lf", &x, &T);

    Result result = cosx(1.0, x, 1, true, T);

    // 打印结果，保留7位小数
    printf("%ld %.7lf\n", result.count, result.value);

    return 0;
}
