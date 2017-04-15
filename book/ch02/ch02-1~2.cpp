#include <cmath>
#include <cstdio>

int main()
{
    printf("2-1:\n");
    for(int a = 1; a <= 9; a++)
    {
        for(int b = 1; b <= 9; b++)
        {
            int n = a*1100 + b*11;
            int m = floor(sqrt(n) + 0.5);
            if( m*m == n)
                printf("%d\n", n);
        }
    }

    printf("2-2\n");
    int n, count = 0;
    scanf("%d", &n);
    while(n > 1)
    {
        if(n%2 == 1)
            n = n*3 + 1;
        else
            n /= 2;
        count++;
    }
    printf("%d\n", count);
    return 0;
}