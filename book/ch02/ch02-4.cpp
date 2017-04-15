#include <cmath>
#include <cstdio>
#include <ctime>

int main()
{
    int n;
    const int MOD = 1000000;
    long long S = 0;
    scanf("%d", &n);
    n >= 25 ? n = 25 : n;
    for(int i = 1; i <= n; i++)
    {
        int factorial = 1;
        for(int j = 1; j <= i; j++)
            factorial = factorial * j % MOD;
        S = (S + factorial) % MOD;
    }
    printf("%lld\n", S);
    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
}