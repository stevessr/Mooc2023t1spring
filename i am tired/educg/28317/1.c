#include <stdio.h>

void exchange(float * a, float * b)
{
    if (*a > *b)
    {
        float temp = *a;
        *a = *b;
        *b = temp;
    }
}
int main()
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    exchange(&a, &b);
    exchange(&a, &c);
    exchange(&b, &c);
    printf("%g %g %g", a, b, c);
    return 0;
}