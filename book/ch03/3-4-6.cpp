#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        char s[81];
        scanf("%s", s);
        int n = strlen(s);
        int min_period = n;
        for(int period = n; period >= 1; period--)
        {
            if(n%period)
                continue;
            int flag = 1;
            char period_s[81];
            strncpy(period_s, s, period);
            for(int i = 0; i < n; i += period)
            {
                for(int j = 0; j < period; j++)
                {
                    if(s[i + j] != period_s[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    true;
                else
                    break;
            }
            flag ? min_period = period : false; 
        }
        printf("%d\n", min_period);
        T == 0 ? true : printf("\n");
    }
}