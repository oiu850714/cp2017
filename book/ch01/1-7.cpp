#include <cmath>
#include <cstdio>

int main()
{
    int year;
    scanf("%d", &year);
    if(year % 400 == 0)
        printf("yes\n");
    else if(year % 100 == 0)
        printf("no\n");
    else if(year % 4 == 0)
        printf("yes\n");
    else
        printf("no\n");
}