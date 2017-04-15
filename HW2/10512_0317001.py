from itertools import accumulate

while True:
    num = input()
    if int(num) == 0:
        break
    arr = [int(i) for i in input().split()]

    ###### this is hand-coded prefix sum ######
    # prefix_sum = [0]
    # for i in range(len(arr)):
    #     prefix_sum.append(prefix_sum[-1] + arr[i])
    # print(prefix_sum)
    ##########################################

    prefix_sum = [0] + list(accumulate(arr))
    sorted_prefix_sum = sorted(prefix_sum)
    del prefix_sum
    
    cur_num = -1000000000
    same_num = 1
    balance_num = 0
    for i in sorted_prefix_sum:
        if i != cur_num:
            cur_num = i
            if(same_num >= 2):
                balance_num = balance_num + ((same_num * (same_num - 1)) // 2)
            same_num = 1
        else:
            same_num += 1
    if(same_num >= 2):
        balance_num = balance_num + ((same_num * (same_num - 1)) // 2)
    # if block deals with case that last same numbers in sorted_prefix_sum
    print(balance_num)
        