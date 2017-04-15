#include <cmath>
#include <cstdio>

int main()
{
    int L1, L2, L3, t; 
    scanf("%d%d%d", &L1, &L2, &L3);
    if(L1 > L2) { t = L1; L1 = L2; L2 = t; }
    if(L1 > L3) { t = L1; L1 = L3; L3 = t; }
    if(L2 > L3) { t = L2; L2 = L3; L3 = t; }
    if( L1 + L2 < L3)
        printf("not a triangle\n");
    else if( L1 * L1 + L2 * L2 == L3 * L3)
        printf("yes\n");
    else
        printf("no\n");
}
