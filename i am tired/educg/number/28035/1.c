#include <stdio.h>
void order(double *f1, double *f2)
{
    if (*f1 > *f2)
    {
        double temp = *f1;
        *f1 = *f2;
        *f2 = temp;
    }
}
int main()
{
    double a[3];
    scanf("%lf %lf %lf", a, a + 1, a + 2);
    order(a, a + 1), order(a + 1, a + 2), order(a, a + 1);
    printf("%g %g %g", *a, *(a + 1), *(a + 2));
}