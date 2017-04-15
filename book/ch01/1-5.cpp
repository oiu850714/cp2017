#include <cmath>
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%.2f", n > 3 ? n * 95 * 0.85: n * 95);
}