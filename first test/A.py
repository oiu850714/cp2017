"""
try:
    list_1 = input().strip()
except:
    exit()
while list_1:
    list_1 = list_1.split(" ")
    list_2 = input().strip().split(" ")
    result = 0
    for int1, int2 in zip(list_1, list_2):
        result += int(int1) * int(int2)
    print(result)
    list_1 = input().strip()
"""

import sys
flag = 0
for line in sys.stdin:
    if flag == 0:
        X = [int(x) for x in line.strip().split()]
        flag = 1
    else:
        Y = [int(y) for y in line.strip().split()]
        flag = 0
        result = 0
        for x, y in zip(X, Y):
            result += x*y
        print(result)



