first_line = input().split()
n, k = int(first_line[0]), int(first_line[1])
L = [int(i) for i in input().split()]

worst_error = max(L) - min(L)
best_error = 0
ans_triple = []

while worst_error != best_error:
    cur_answer = (worst_error + best_error) // 2
    cur_min = cur_max = L[0]
    cur_L, cur_R = 0, 0
    for i in range(len(L)):
        if L[i] >= cur_min and L[i] <= cur_max:
            cur_R += 1
        elif L[i] > cur_max and L[i] - cur_min <= cur_answer * 2:
            cur_max = L[i]
            cur_R += 1
        elif L[i] < cur_min and cur_max - L[i] <= cur_answer * 2:
            cur_min = L[i]
            cur_R += 1
        else:
            if cur_L == cur_R:
                ans_triple.append((cur_L + 1, cur_R + 1, (cur_max + cur_min)//2))
            else:
                ans_triple.append((cur_L + 1, cur_R - 1 + 1, (cur_max + cur_min)//2))
            # + 1 for 1-base...
            cur_L = cur_R = i
            cur_min = cur_max = L[i]
    #ans_triple.append((cur_L + 1, cur_R-1 + 1, (cur_max + cur_min//2)))
    if cur_L == cur_R:
        ans_triple.append((cur_L + 1, cur_R + 1, (cur_max + cur_min)//2))
    else:
        ans_triple.append((cur_L + 1, cur_R - 1 + 1, (cur_max + cur_min)//2))
    if len(ans_triple) <= k:
        worst_error = cur_answer
        ans = ans_triple
    else:
        best_error = cur_answer + 1
    ans_triple = []

k_ans = []

remain_cut = k - len(ans)

for (a,b,c) in ans:
    if a == b:
        continue
    else:
        tmp = a
        flag = 0
        while tmp <= b and remain_cut:
            ans.append((tmp,tmp,c))
            remain_cut -= 1
            tmp += 1
            if remain_cut == 0:
                ans.append((tmp, b, c)) # last element
                ans.remove((a, b, c))
                flag = 1
                break
        if flag:
            break

for (a, b, c) in sorted(ans):
    print(a, b, c)
