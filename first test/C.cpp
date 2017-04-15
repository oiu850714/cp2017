#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int num_bulbs;
        scanf("%d", &num_bulbs);
        int light_bulbs = num_bulbs;
        for(int i = 1; i*i <= num_bulbs; i++) //start from 1!!! because bulbs are numbered from one
        {
            --light_bulbs;
        }
        printf("%d\n", light_bulbs);
    }
}