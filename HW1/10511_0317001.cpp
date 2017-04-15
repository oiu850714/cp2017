#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#define BUF_SIZE 10000

void f1(int *arr1, int diff_num);
void f2(int *arr2, int diff_num);
void f3(int *arr3, int diff_num);
void f4(int *arr4, int diff_num);
void f5(int *arr5, int diff_num);

int main()
{
    int  n;
    while(scanf("%d", &n) && n!=0)
    {
        int value_arr[6];
        int map_to[6];
        for(int i = 1; i <=  n; ++i)
        {
            scanf("%d", value_arr + i);
            map_to[value_arr[i]] = 1;
        }
        int flag = 0;
        for(int i = 1; i <= n; ++i)
        {
            /*
            printf("value_arr[i] : %d, value_arr[value_arr[i]] : %d\n",
                    value_arr[i], value_arr[value_arr[i]] );
            */
            if(value_arr[value_arr[i]] != value_arr[i])
            {
                flag = 1;
                break;
            }
        }
        flag == 0 ? printf("yes\n") : printf("no\n");
        /*
        int diff_num = 0;
        for( auto i : map_to)
        {
            if(i == 1)
                diff_num++;
        }
        switch(n)
        {
            case 1:
                f1(value_arr, diff_num);
                break;
            case 2:
                f2(value_arr, diff_num);
                break;
            case 3:
                f3(value_arr, diff_num);
                break;
            case 4:
                f4(value_arr, diff_num);
                break;
            case 5:
                f5(value_arr, diff_num);
                break;
        }
        */

    }
}


//iterate on g, find h

// n to m: total m^n different functions

void f1(int *arr1, int diff_num)
{
    printf("yes\n");
}

void f2(int *arr2, int diff_num)
{
    for(int m = 1; m <= 2; m++)
    {   
        for(int g1 = 1; g1 <= m; g1++)
        {
            for(int g2 = 1; g2 <= m; g2++)
            {
                
            }
        }
    }
    printf("no\n");
}

void f3(int *arr3, int diff_num)
{
    for(int m = 1; m <= 3; m++)
    {   
        for(int g1 = 1; g1 <= m; g1++)
        {
            for(int g2 = 1; g2 <= m; g2++)
            {
                for(int g3 = 1; g3 <= m; g3++)
                {

                }
            }
        }
    }
    printf("no\n");
}

void f4(int *arr4, int diff_num)
{
    for(int m = 1; m <= 4; m++)
    {   
        for(int g1 = 1; g1 <= m; g1++)
        {
            for(int g2 = 1; g2 <= m; g2++)
            {
                for(int g3 = 1; g3 <= m; g3++)
                {
                    for(int g4 = 1; g4 <= m; g4++)
                    {
                        
                    }
                }
            }
        }
    }
    printf("no\n");
}

void f5(int *arr5, int diff_num)
{
    for(int m = 1; m <= 5; m++)
    {   
        for(int g1 = 1; g1 <= m; g1++)
        {
            for(int g2 = 1; g2 <= m; g2++)
            {
                for(int g3 = 1; g3 <= m; g3++)
                {
                    for(int g4 = 1; g4 <= m; g4++)
                    {
                        for(int g5 = 1; g5 <= m; g5++)
                        {

                        }
                    }
                }
            }
        }
    }
    printf("no\n");
}