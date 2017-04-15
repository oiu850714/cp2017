#include <cmath>
#include <cstdio>

int main()
{
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)
        && a!=0 && b!=0 && c!=0)
    {
        printf("%.*f\n", c, ((double)a/(double)b));
    }
}