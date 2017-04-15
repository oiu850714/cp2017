#include <cstring>
#include <cstdio>

int main()
{
    char s[81];
    int T;
    scanf("%d", &T);
    while(T--)
    {   
        scanf("%s", s);
        int n = strlen(s);
        int cur_num_O = 0, total_score = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'O')
            {
                total_score += ++cur_num_O;
            }
            else
            {
                cur_num_O = 0;
            }
        }
        printf("%d\n", total_score);
    }
}