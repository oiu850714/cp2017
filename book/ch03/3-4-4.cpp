#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#define C_MASS 12.01
#define H_MASS 1.008
#define O_MASS 16.00
#define N_MASS 14.01

int main()
{
    int T;
    char s[81];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        int n = strlen(s);
        char cur_atom = '\0';
        int cur_num = 1;
        double molar_mass = 0;
        int two_digit_flag = 0;
        for(int i = 0; i < n; i++)
        {
            if(isdigit(s[i]))
            {
                two_digit_flag == 0 ?
                    cur_num = (s[i] - '0') :
                    cur_num = (10*cur_num) + (s[i] - '0');
                two_digit_flag = 1;
            }
            else
            {
                // plus...
                switch(cur_atom)
                {
                    case 'C':
                        molar_mass += C_MASS * cur_num;
                        break;
                    case 'H':
                        molar_mass += H_MASS * cur_num;
                        break;
                    case 'O':
                        molar_mass += O_MASS * cur_num;
                        break;
                    case 'N':
                        molar_mass += N_MASS * cur_num;
                        break;
                    default:
                    // c is digit or '\0'
                        break;
                }
                cur_num = 1;
                cur_atom = s[i];
                two_digit_flag = 0;
            }
        }
        /*
        if(!isdigit(s[n-1]))
        {
            switch(s[n-1])
            {
                case 'C':
                    molar_mass += C_MASS;
                    break;
                case 'H':
                    molar_mass += H_MASS;
                    break;
                case 'O':
                    molar_mass += O_MASS;
                    break;
                case 'N':
                    molar_mass += N_MASS;
                    break;
                default:
                // c is digit or '\0'
                    break;
            }
        }
        */
        switch(cur_atom)
        {
            case 'C':
                molar_mass += C_MASS * cur_num;
                break;
            case 'H':
                molar_mass += H_MASS * cur_num;
                break;
            case 'O':
                molar_mass += O_MASS * cur_num;
                break;
            case 'N':
                molar_mass += N_MASS * cur_num;
                break;
            default:
            // c is digit or '\0'
                break;
        }
        printf("%.3f\n", molar_mass);
    }    
}