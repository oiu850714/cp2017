#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin;

struct rectangle
{
    int width;
    int height;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int width, height;
    rectangle rec[6];
    while(cin >> rec[0].width >> rec[0].height)
    {
        for(int i = 1; i < 6; i++)
        {
            cin >> rec[i].width >> cin >> rec[i].height;
        }
    }
}