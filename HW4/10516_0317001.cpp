#include <cstdio>
#include <cstdlib>

int low_bit(int n);

int main()
{

}


int low_bit(int n)
{
    return (n&-n);
}