#include <cstdio>
#include <cctype>
#include <cstring>
#define MAXN 100005
int ans[MAXN];

int main()
{
    memset(ans, 0, sizeof(ans));
    for(int m = 1; m < MAXN; m++)
    {
        int x = m, y = m;
        while(x > 0)
        {
            y += x%10;
            x /= 10;
        }
        if(ans[y] == 0 || m < ans[y])
            ans[y] = m;
    }
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}