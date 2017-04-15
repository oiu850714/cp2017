from math import factorial

t = int(input())

while t:
    n, i = [int(k) for k in input().split()]
    L = list(range(n))
    cur_ith = 0
    ans = []
    while len(L) > 1:
        #print("len(L):", len(L))
        #print("cur_ith:", cur_ith)
        tmp_fac = factorial(len(L)-1)
        for index, term in enumerate(L):
            #print("outer index:", index)
            #print("index:",index)
            #print("index * tmp_fac: ", index * tmp_fac)
            if cur_ith + (index * tmp_fac) >= i:
            #this if means that you pick the non-last element
            #e.g. [0 1 2 3 4 5 6 7 8 9] you pick 2
                #print("cur_ith", cur_ith, "index:", index)
                cur_ith += (index - 1)* tmp_fac
                ans.append(L[index - 1] + 1)
                del L[index - 1]
                break
            if index == len(L) - 1:
            #this if means that you pick the non-last element
            #e.g. [0 1 4 5 6 9] you pick 9
            #important!!!! when you pick the last element
            #cur_ith + index * tmp_fac is still less than i!!!
                cur_ith += index * tmp_fac
                ans.append(L[index] + 1)
                del L[index]
                break
    ans.append(L[0] + 1)
    del L[0]
    print("(", end='')
    for index, i in enumerate(ans):
        if index == len(ans) - 1:
            print(i, end=')')
        else:
            print(i, end=',')
    print()


    t -= 1