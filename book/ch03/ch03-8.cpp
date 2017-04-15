#include <cstdio>
#include <cstring>
#define MAXN 105

bool less(const char* s, int p, int q, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(s[(p + i)%n] < s[(q + i)%n])
            return true;
    }
    return false;
}

int main()
{
    int T;
    char s[MAXN];
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%s", s);
        n = strlen(s);
        int ans = 0;//answer's starting position
        for(int i = 0; i < n; i++)
        {
            if(less(s, i, ans, n))
                ans = i;
        }
        for(int i = 0; i < n; i++)
            printf("%c", s[(ans + i)%n]);
        printf("\n");
    }
}