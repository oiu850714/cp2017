#include <cmath>
#include <cstdio>

int main()
{
    double n;
    const double pi = acos(-1.0);
    scanf("%lf", &n);
    printf("%f\n", sin(n / 180.0 * pi));
    printf("%f\n", cos(n / 180.0 * pi));
}