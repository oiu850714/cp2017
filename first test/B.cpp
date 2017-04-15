#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int main()
{
    int dim;
    long long array[10000];
    while(scanf("%d", &dim) != EOF)
    {
        long long square_result = 0;
        for(int i = 0; i < dim; ++i)
        {
            scanf("%lld", array+i);
        }
        for(int i = 0; i < dim; ++i)
        {
            square_result += array[i]*array[i];
        }
        //double d_square_result = square_result;
        printf("%.3lf\n", sqrt(square_result));
    }
}