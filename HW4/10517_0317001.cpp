#include <vector>
#include <cstdio>
#include <cstdlib>

using std::vector;

void merge_sort(vector<int>& vec, long long& inversion_pair)
{
    if(vec.size() <= 1)
        return;
    else
    {
        vector<int> left_vec(vec.begin(), vec.begin() + vec.size() / 2);
        vector<int> right_vec(vec.begin() + vec.size() / 2, vec.end());
        merge_sort(left_vec, inversion_pair);
        merge_sort(right_vec, inversion_pair);

        int left_ptr = 0, right_ptr = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            if(right_ptr == right_vec.size())
            {
                vec[i] = left_vec[left_ptr++];
            }
            else if(left_ptr == left_vec.size())
            {
                vec[i] = right_vec[right_ptr++];
            }
            else if(right_vec[right_ptr] < left_vec[left_ptr])
            {
                inversion_pair += left_vec.size() - left_ptr;
                vec[i] = right_vec[right_ptr++];
            }
            else
            {
                vec[i] = left_vec[left_ptr++];
            }
        }
    }

}

int main()
{
    int nun_case;
    scanf("%d", &nun_case);
    while(nun_case--)
    {
        int arr_len;
        scanf("%d", &arr_len);
        vector<int> arr;
        int tmp;
        for(int i = 0; i < arr_len; i++)
        {
            scanf("%d", &tmp);
            arr.push_back(tmp);
        }
        long long inversion_pair = 0;
        merge_sort(arr, inversion_pair);
        printf("%lld\n", inversion_pair);
    }
}