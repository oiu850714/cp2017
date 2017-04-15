#include <cmath>
#include <cstdio>

int main()
{
    int first, second;
    while(scanf("%d%d", &first, &second) == 2 
        && first != 0 && second != 0)
    {   
        double sum = 0;
        for(long long i = first; i <= second; i++)
        {
            sum += 1.0/double(i*i);
        }
        printf("%.5f\n", sum);
    }
}