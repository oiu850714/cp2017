#include <cstring>
#include <cstdio>

int main()
{
    char s[] = "1234";
    printf("len of s: %d\n\n", strlen(s));
    for(int i = 0 ; i < strlen(s); i++)
        printf("%c ", s[i]);
    printf("\n");
    for(int i = 0; s[i]; i++)
        printf("%c ", s[i]);
    printf("\n");
}