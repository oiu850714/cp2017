#include <cmath>
#include <cstdio>

int main()
{
    printf("%d\n", 11111*11111);
    printf("%d\n", 111111*111111);
    printf("%d\n", 111111111*111111111);
    printf("%f\n", 11111.0*11111.0);
    printf("%f\n", 111111.0*111111.0);
    printf("%f\n", 111111111.0*111111111.0);
    // 12345678987654320.000000, loss precision
    printf("%f\n", sqrt(10));
    printf("%f\n", sqrt(-10));
    // domain error
    printf("%f\n", 1.0/0.0);
    // inf
    //printf("%f\n", 0,0/0,0);
    // line above failed, https://msdn.microsoft.com/zh-tw/library/aa691146(v=vs.71).aspx
    //printf("%d\n", 1/0);
    // failed again
    
    printf("\n\n\n");

    int a, b;
    scanf("%d%d", &a, &b);
    printf("%c %c\n", a, b);
    return 0;
}