#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector; using std::string; using std::cout;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        char DNA_set[50][1001];
        for(int i = 0; i < m; i++)
        {
            scanf("%s", DNA_set[i]);
        }
        int error = 0;
        char ans[1010] = {};
        char ACGT[5] = "ACGT";
        for(int j = 0; j < n; j++)
        {
            int count_for_ACGT[4] = {};
            //note that A C G T is lexical order!
            for(int i = 0; i < m; i++)
            {
                switch(DNA_set[i][j])
                {
                    case 'A':
                        count_for_ACGT[0]++; break;
                    case 'C':
                        count_for_ACGT[1]++; break;
                    case 'G':
                        count_for_ACGT[2]++; break;
                    case 'T':
                        count_for_ACGT[3]++; break;
                }
            }
            int max_index = 0;
            for(int i = 0; i < 4; i++)
            {
                if(count_for_ACGT[max_index] < count_for_ACGT[i])
                    max_index = i;
            }
            ans[j] = ACGT[max_index];
            error += m - count_for_ACGT[max_index];
        }
        printf("%s\n%d\n", ans, error);
        /*
        int min_error = 1000 * 51;
        //maximun error is probably around 1000 * 51
        vector<string> solution;
        for(int set_index_1 = 0; set_index_1 < m; set_index_1++)
        {//for every string
            int tmp_error = 0;
            for(int set_index_2 = 0; set_index_2 < m; set_index_2++)
            {//for other strings to be compared
                if(set_index_1 == set_index_2)
                    continue;
                    
                for(int str_index = 0; str_index < n; str_index++)
                {//for every char to be compared
                    if(DNA_set[set_index_1][str_index] 
                            != DNA_set[set_index_2][str_index])
                    {
                        tmp_error++;
                    }
                }
            }
            if(tmp_error < min_error)
            {
                min_error = tmp_error;
                solution.clear();
                solution.push_back(DNA_set[set_index_1]);
            }
            else if(tmp_error == min_error)
            {
                solution.push_back(DNA_set[set_index_1]);
            }
        }
        sort(solution.begin(), solution.end());
        cout << solution[0] << "\n" << min_error << "\n";
        */
        // above is fucking shit
    }
}