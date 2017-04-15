#include <cstring>
#include <cctpye>
#include <cstdio>

const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome", "a regular palindrome",
                     "a mirrored string", "a mirrored palindrome"};
char r(char ch)
{
    if (isalpha(ch))
        return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main()
{
    char input[101];
    while (scanf("%s", input) == 1)
    {
        int len = strlen(input);
        int p = 1, m = 1;
        for (int i = 0; i < (len + 1) / 2; i++)
        {
            if (input[i] != input[len - 1 - i])
                p = 0; //not palindrome
            if (r(input[i]) != input[len - 1 - i])
                m = 0; //not mirrored
        }
        printf("%s -- is %s.\n\n", input, msg[m * 2 + p]);
    }
    return 0;
}