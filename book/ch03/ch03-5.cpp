#include <cstring>
#include <cstdio>

int main()
{
    char keyboard_keys[] = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i, c;
    while((c = getchar()) != EOF)
    {
        for(i = 1; keyboard_keys[i] && keyboard_keys[i]!=c; i++)
            ;
        if(keyboard_keys[i])
            putchar(keyboard_keys[i-1]);
        else
            putchar(c);
    }
    return 0;
}