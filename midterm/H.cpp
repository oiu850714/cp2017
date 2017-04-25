#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::reverse;
char BASE_64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        unsigned long long i;
        cin >> i;
        string result;
        do
        {
            result.push_back(BASE_64[i%64]);
            i /= 64;
        }
        while(i);
        reverse(result.begin(), result.end());
        cout << result << "\n";
    }
}