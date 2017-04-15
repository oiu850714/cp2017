#include <cstdio>
#include <cstdlib>

#define STR "This puzzle has no configuration\n"

int main()
{
    char puzzle[5][5];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            scanf("%c", &puzzle[i][j]);
        }
    }
    char cur_command;
    scanf("%c", &cur_command);
    //eat newline after puzzle input;

    while(scanf("%c", &cur_command) == 1 && cur_command != '0')
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(puzzle[i][j] == '0')
                {
                    if(cur_command == 'A')
                    {
                        if(i == 0)
                        {
                            printf(STR);
                            return 1;
                        }
                        else
                        {
                            puzzle[i][j] = puzzle[i-1][j];
                            puzzle[i-1][j] = '0';
                        }
                    }
                    else if(cur_command == 'B')
                    {
                        if(i == 4)
                        {
                            printf(STR);
                            return 1;
                        }
                        else
                        {
                            puzzle[i][j] = puzzle[i+1][j];
                            puzzle[i+1][j] = '0';
                        }
                    }
                    else if(cur_command == 'L')
                    {
                        if(j == 0)
                        {
                            printf(STR);
                            return 1;
                        }
                        else
                        {
                            puzzle[i][j] = puzzle[i][j-1];
                            puzzle[i][j-1] = '0';
                        }
                    }
                    else if(cur_command == 'R')
                    {
                        if(j == 4)
                        {
                            printf(STR);
                            return 1;
                        }
                        else
                        {
                            puzzle[i][j] = puzzle[i][j+1];
                            puzzle[i][j+1] = '0';
                        }
                    }
                    goto YOU_SHOULD_SCAN_NEXT_COMMAND;
                }
            }
        }
        YOU_SHOULD_SCAN_NEXT_COMMAND:
        ;
    }
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            printf("%c", puzzle[i][j]);
        printf("\n");
    }
}