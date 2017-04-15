#include <cstdio>
#include <cstring>
#define MAXN 10000000 + 10
char s[MAXN];
int main()
{
    scanf("%s", s);
    int tot = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1') tot++;
    }
    printf("%d\n", tot);
}