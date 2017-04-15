#include <cstring>
#include <cstdio>

int main()
{
    int c;
    int flag = 0;
    while((c = getchar()) != EOF)
    {
        if(c == '"')
        {
            if(flag == 0)
            {
                printf("``");
                flag = 1;
            }
            else
            {
                printf("''");
                flag = 0;
            }
        }
        else
        {
            printf("%c", c);
        } 
    }
}