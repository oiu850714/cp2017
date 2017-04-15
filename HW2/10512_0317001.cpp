#include<cstdio>
#include<cstdlib>

int compare (const void * a, const void * b)
{
  return ( *(long long int*)a - *(long long int*)b );
}


int main()
{
    int case_num;
    long long int num_arr[100001];
    long long int prefix_sum[100001];
    prefix_sum[0] = 0;
    while(scanf("%d", &case_num) && case_num != 0)
    {
        for(int i = 1; i <= case_num; i++)//fucking 1 base
        {
            scanf("%lld", num_arr + i);
            prefix_sum[i] = prefix_sum[i - 1] + num_arr[i];
        }
        qsort(prefix_sum, case_num + 1, sizeof(long long int), compare);

        long long int cur_num = -10000000;
        long long int num_of_same_num = 1;
        long long int num_of_balance_num = 0;

        for(int i = 0; i < case_num + 1; i++)//size of prefix_sum = case_num + 1 !!
        {
            if(prefix_sum[i] != cur_num)
            {
                cur_num = prefix_sum[i];
                if(num_of_same_num >= 2)
                {
                    num_of_balance_num += num_of_same_num * (num_of_same_num - 1) / 2;
                }
                num_of_same_num = 1;
            }
            else
            {
                num_of_same_num++;
            }
        }
        if(num_of_same_num >= 2)
        {
            num_of_balance_num += num_of_same_num * (num_of_same_num - 1) / 2;
        }
        printf("%lld\n", num_of_balance_num);
    }
}