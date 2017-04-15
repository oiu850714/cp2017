def normal_multiplication(f, g):
    res = [0 for i in range(len(f) + len(g) - 1)]
    # len(f) + len(g) - 1 = x^0 to x^(2n-1) terms
    for i in range(len(f)):
        for j in range(len(g)):
            res[i+j] += f[i] * g[j]
    return res

def poly_plus(f, g):
    if len(f) == len(g):
        return [f[i] + g[i] for i in range(len(f))]
    elif len(f) > len(g):
        return [f[i] + g[i] for i in range(len(g))] + f[-1:]
        # use len(g) cause len(g) < len(f)
    else:
        return [f[i] + g[i] for i in range(len(f))] + g[-1:]
        # and vise versa

def poly_subtract(f, g):
    if len(f) == len(g):
        return [f[i] - g[i] for i in range(len(f))]
    elif len(f) > len(g):
        return [f[i] - g[i] for i in range(len(g))] + f[len(g):]
        # the same reason in poly_plus case for using len(g)
        # fuck you for last terms.........
    else:
        return [f[i] - g[i] for i in range(len(f))] + g[len(f):] #[i*(-1) for i in g[len(f):]]

def karatsuba(f, g):
    f_second = f[:len(f)//2]
    f_first = f[len(f)//2:]
    g_second = g[:len(g)//2]
    g_first = g[len(g)//2:]
    
    #f_second_multi_g_second = []
    if len(f_second) <= 32:
        f_second_multi_g_second = normal_multiplication(f_second, g_second)
    else:
        f_second_multi_g_second = karatsuba(f_second, g_second)
    
    #f_first_multi_g_first = []
    if len(f_first) <= 32:
        f_first_multi_g_first = normal_multiplication(f_first, g_first)
    else:
        f_first_multi_g_first = karatsuba(f_first, g_first)
    
    f_first_plus_f_second = poly_plus(f_first, f_second)
    g_first_plus_g_second = poly_plus(g_first, g_second)

    #f_f_plus_f_s_multi_g_f_plus_g_s = []
    if len(f_first_plus_f_second) <= 32:
        f_f_plus_f_s_multi_g_f_plus_g_s = normal_multiplication(
            f_first_plus_f_second, g_first_plus_g_second)
    else:
        f_f_plus_f_s_multi_g_f_plus_g_s = karatsuba(
            f_first_plus_f_second, g_first_plus_g_second)

    tmp = poly_subtract(f_f_plus_f_s_multi_g_f_plus_g_s, f_first_multi_g_first)
    ad_plus_bc = poly_subtract(tmp, f_second_multi_g_second)
    res = [0 for i in range(len(f) + len(g) - 1)]
    
    for i in range(len(f_second_multi_g_second)):
        res[i] += f_second_multi_g_second[i]
    
    len_f = len(f)
    for i in range(len(ad_plus_bc)):
        res[i + len_f//2] += ad_plus_bc[i]
    if len(f) % 2:
        for i in range(len(f_first_multi_g_first)):
            res[i + len_f  - 1] += f_first_multi_g_first[i]
    else:
        for i in range(len(f_first_multi_g_first)):
            res[i + len_f] += f_first_multi_g_first[i]
    # dealing with f.size() is odd or even

    return res


t = int(input())
while t:
    n = int(input()) 
    f = [int(i) for i in input().split()]
    g = [int(i) for i in input().split()]
    [print(i, '', end='') for i in karatsuba(f, g)]
    print()
    t -= 1