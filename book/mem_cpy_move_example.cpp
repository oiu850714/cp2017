#include <cstring>
#include <cstdio>

int main()
{
    char str1[11] = "1234567890";
    printf("%s\n", str1);
    memcpy(str1, str1 + 3, 5);
    printf("%s\n", str1);
    char str2[11] = "1234567890";
    printf("%s\n", str2);
    memmove(str2, str2 + 3, 5);
    printf("%s\n", str2);
    
}