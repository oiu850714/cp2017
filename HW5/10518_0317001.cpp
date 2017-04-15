#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;

unsigned long long factorial(unsigned n)
{
    unsigned long long ans = 1;
    for(unsigned long long i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {   
        unsigned long long n, i;
        scanf("%llu%llu", &n, &i);

        vector<int> permutation_pool;
        for(int i = 1; i <= n; i++)
        {
            permutation_pool.push_back(i);
        }
        
        unsigned long long cur_ith = 0;
        vector<int> ans;
        while(permutation_pool.size() > 1)
        {
            unsigned long long temp_fac = factorial(permutation_pool.size() - 1);
            unsigned long long n_element = 
            /*
            for(unsigned long long index = 0; index < permutation_pool.size(); index++)
            {
                if(cur_ith + (index * temp_fac) >= i)
                {
                    
                    printf("===============\n");
                    printf("cur_ith: %llu\n", cur_ith);
                    printf("cur_index: %llu\n", index);
                    printf("index * temp_fac :%llu\n", index * temp_fac);
                    printf("cur_ith + (index * temp_fac): %llu\n", cur_ith + (index*temp_fac));
                    printf("i: %llu\n", i);
                    
                    cur_ith += (index - 1)* temp_fac;
                    ans.push_back(permutation_pool[index - 1]);
                    permutation_pool.erase(permutation_pool.begin() + (index - 1));
                    break;
                }
                if(index == permutation_pool.size() - 1)
                {
                    
                    printf("===============\n");
                    printf("cur_ith: %llu\n", cur_ith);
                    printf("cur_index: %llu\n", index);
                    printf("index * temp_fac :%llu\n", index * temp_fac);
                    printf("cur_ith + (index * temp_fac): %llu\n", cur_ith + (index*temp_fac));
                    printf("i: %llu\n", i);
                    
                    cur_ith += index * temp_fac;
                    ans.push_back(permutation_pool[index]);
                    permutation_pool.pop_back();
                    break;
                }
            }*/

        }
        ans.push_back(permutation_pool[0]);
        permutation_pool.pop_back();
        printf("(");
        for(int index = 0; index < ans.size(); index++)
        {
            if(index == ans.size() - 1)
                printf("%d)", ans[index]);
            else
                printf("%d,", ans[index]);
        }
        printf("\n");
    }
}