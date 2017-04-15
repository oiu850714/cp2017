#include <cmath>
#include <cstdio>

int main()
{
    for(int i = 100; i <= 999; i++)
    {
        int _100 = i/100;
        int _10 = (i%100)/10;
        int _1 = i%10;
        if(i == _1*_1*_1 + _10*_10*_10 + _100*_100*_100)
            printf("%d\n", i); 
    }
    return 0;
}