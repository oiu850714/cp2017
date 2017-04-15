#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define BUF_SIZE 10000

bool is_higher_prec(char op, char stack_top);

int main()
{
    char input[BUF_SIZE];
    char oprs[BUF_SIZE];
    char post_exp[BUF_SIZE];
    while(fgets(input, BUF_SIZE, stdin))
    {
        //printf("input: %s\n", input);
        int oprs_len = 0;
        int post_exp_len = 0;
        int len = strlen(input);
        for(int i = 0; i < len; i++)
        {
            //printf("------\n%c\n------\n", input[i]);
            if(isdigit(input[i]))
            {
                //printf("is digit! : %c\n", input[i]);
                post_exp[post_exp_len] = input[i];
                post_exp_len+=1;
            }
            else if(input[i] == ' ' || input[i] == '\n')
            {
                //printf("is space!\n");
                continue;
            }
            else if(input[i] == ')')
            {
                while( oprs[oprs_len - 1] != '(')
                {
                    post_exp[post_exp_len] = oprs[oprs_len - 1];
                    post_exp_len += 1;
                    oprs_len -= 1;
                }
                oprs_len -= 1;   
            }
            else
            {
                while( oprs_len && oprs[oprs_len - 1] != '(' 
                    && is_higher_prec(input[i], oprs[oprs_len - 1]) )
                // oprs[oprs_len-1] is "top" of the stack
                {
                    //printf("op ?!?!:%c\n", oprs[oprs_len]);
                    post_exp[post_exp_len] = oprs[oprs_len - 1];
                    post_exp_len += 1;
                    oprs_len -= 1;
                }
                oprs[oprs_len++] = input[i];
                //printf("LEN:%d\nContent:%s\n", oprs_len, oprs);
            }
            //printf("i iter's post_exp:%s\n", post_exp);
        }
        while(oprs_len)
        {
            post_exp[post_exp_len] = oprs[oprs_len - 1];
            post_exp_len += 1;
            oprs_len -= 1;
        }
        post_exp[post_exp_len] = '\0';
        //printf("what the fuck?? len: %d  post_exp:%s\n", post_exp_len, post_exp);




        long long result[10000], result_ptr = 0;
        //FUCK YOU long long
        for( auto c : post_exp)
        {
            if(isdigit(c))
            {
                result[result_ptr] = c - 48; // ASCII
                result_ptr += 1;
            }
            else
            {
                c == '+' ?
                    result[result_ptr - 2] = (result[result_ptr - 2] + result[result_ptr - 1])%1000000007
                    :result[result_ptr - 2] = (result[result_ptr - 2] * result[result_ptr - 1])%1000000007;
                result[result_ptr - 2] %= 1000000007;
                result_ptr -= 1;

            }
        }
        printf("%d\n", result[0]);

    }
}

bool is_higher_prec(char op, char stack_top)
{
    if (op == '+' && (stack_top == '*' or stack_top == '+'))
        return true;
    else if (op == '*' && stack_top == '*')
        return true;
    else
        return false;
}