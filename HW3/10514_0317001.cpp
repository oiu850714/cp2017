#include <vector>
#include <cstdio>
#include <cstring>

using std::vector;

vector<int> karatsuba(const vector<int>& f, const vector<int>& g);
void poly_plus(vector<int>& plus, const vector<int>& f, const vector<int>& g);
vector<int> normal_multiplication(vector<int>& f, vector<int>& g);
void remain_element(vector<int>& plus, const vector<int>& f, int start_pos);
vector<int> use_karatsuba_or_normal(vector<int>& f, vector<int>& g, int size);
void poly_subtract(vector<int>& f, vector<int>& g);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> f(n, 0), g(n, 0);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &f[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &g[i]);
        }
        vector<int> res = karatsuba(f, g);
        for(int i = 0; i < res.size(); i++)
            i + 1 < res.size() ? printf("%d ", res[i]) : printf("%d\n", res[i]);
    }
}

vector<int> karatsuba(const vector<int>& f, const vector<int>& g)
{
    vector<int> f_second(f.begin(), f.begin() + f.size()/2);
    vector<int> f_first(f.begin() + f.size()/2, f.end());
    vector<int> g_second(g.begin(), g.begin() + g.size()/2);
    vector<int> g_first(g.begin() + g.size()/2, g.end());
    vector<int> f_second_multi_g_second;
    vector<int> f_first_multi_g_first;
    f_second_multi_g_second = use_karatsuba_or_normal(f_second, g_second, f_second.size());
    f_first_multi_g_first = use_karatsuba_or_normal(f_first, g_first, f_first.size());
    
    vector<int> f_first_plus_f_second;
    vector<int> g_first_plus_g_second;
    poly_plus(f_first_plus_f_second, f_first, f_second);
    poly_plus(g_first_plus_g_second, g_first, g_second);
    vector<int> f_f_plus_f_s_multi_g_f_plus_g_s = 
    use_karatsuba_or_normal(f_first_plus_f_second,
                            g_first_plus_g_second, f_first_plus_f_second.size());
    poly_subtract(f_f_plus_f_s_multi_g_f_plus_g_s, f_first_multi_g_first);
    poly_subtract(f_f_plus_f_s_multi_g_f_plus_g_s, f_second_multi_g_second);
    //########### now f_f_plus_f_s_multi_g_f_plus_g_s becomes ab_plus_bc!;
    vector<int>& ad_plus_bc = f_f_plus_f_s_multi_g_f_plus_g_s;
    vector<int> res(f.size() * 2 - 1, 0);
    for(int i = 0; i < f_second_multi_g_second.size(); i++)
    {
        res[i] += f_second_multi_g_second[i];
    }
    int ad_plus_bc_size = ad_plus_bc.size();
    int f_size = f.size();
    for(int i = 0; i < ad_plus_bc_size; i++)
    {
        res[f_size/2 + i] += ad_plus_bc[i];
    }
    for(int i = 0; i < f_first_multi_g_first.size(); i++)
    {
        f.size() % 2 ? res[i + f_size - 1] += f_first_multi_g_first[i]
        : res[i + f_size] += f_first_multi_g_first[i];
        // dealing with f.size() is odd or even
    }
    return res;
}

void remain_element(vector<int>& plus, const vector<int>& f, int start_pos)
{
    for(int i = start_pos; i < f.size(); i++)
    {
        plus.push_back(f[i]);
    }
}

void poly_plus(vector<int>& plus, const vector<int>& f, const vector<int>& g)
{
    int min_size = (f.size() > g.size()? g.size(): f.size());
    for(int i = 0; i < min_size; i++)
    {
        plus.push_back(f[i] + g[i]);
    }
    f.size() > g.size() ? remain_element(plus, f, min_size) : remain_element(plus, g, min_size);
}

vector<int> use_karatsuba_or_normal(vector<int>& f, vector<int>& g, int size)
{
    return size <= 32 ? normal_multiplication(f, g) : karatsuba(f, g);
}

void poly_subtract(vector<int>& f, vector<int>& g)
{
    // condition --g.size()-- is very important, since g.size() is
    // always smaller than f.size()
    // if using f.size(), it will cause segfault
    for(int i = 0; i < g.size(); i++)
    {
        f[i] -= g[i];
    }
}

vector<int> normal_multiplication(vector<int>& f, vector<int>& g)
{
    vector<int> res(f.size() * 2 - 1, 0);
    for(int i = 0; i < f.size(); i++)
    {
        for(int j = 0; j < f.size(); j++)
        {
            res[i + j] += f[i] * g[j];
        }
    }
    return res;
}