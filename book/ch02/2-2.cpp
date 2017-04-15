#include <cmath>
#include <cstdio>

int main()
{
    int a, b, c;
    for(int kase = 1; scanf("%d%d%d", &a, &b, &c) == 3; kase++)
    {
        int flag = 0;
        for(int i = 10; i <= 100; i++)
        {
            if(i%3 == a && i%5 == b && i%7 == c)
            {
                printf("Case %d: %d\n", kase, i);
                flag = 1;
            }
        }
        flag == 0 ? printf("Case %d: No answer\n", kase) : NULL;
    }
}