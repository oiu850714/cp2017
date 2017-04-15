#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using std::cout; using std::cin;

int main()
{
    char array_1[1000000], array_2[1000000];
    long long num_array_1[100], num_array_2[100];
    int arr_index = 0;
    long long result = 0;
    char* tmp_str;
    while(fgets(array_1, 1000000, stdin) && fgets(array_2, 1000000, stdin))
    {
        arr_index = 0;
        tmp_str = strtok(array_1, " \n");
        num_array_1[arr_index] = atol(tmp_str);
        ++arr_index;
        while(tmp_str = strtok(NULL, " \n"))
        {
            num_array_1[arr_index] = atol(tmp_str);
            ++arr_index;
        }
        arr_index = 0;
        tmp_str = strtok(array_2, " \n");
        num_array_2[arr_index] = atol(tmp_str);
        ++arr_index;
        while(tmp_str = strtok(NULL, " \n"))
        {
            num_array_2[arr_index] = atol(tmp_str);
            ++arr_index;
        }
        for(int i = 0; i < arr_index; ++i)
        {
            result += (num_array_1[i] * num_array_2[i]);
        }
        printf("%lld\n", result);
        result = 0;
    }
}
