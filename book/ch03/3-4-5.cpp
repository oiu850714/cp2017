#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int frequency[10] = {0};
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            for(int tmp = i; tmp; tmp/=10)
            {
                frequency[tmp%10]++;
            }
        }
        for(int i = 0; i < 10; i++)
            (i + 1 == 10) ?
                printf("%d\n", frequency[i]) :
                printf("%d ", frequency[i]);
    }
}