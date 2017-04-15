import sys
X = 0
D = 0
for line in sys.stdin:
    X = line.split()
    if len(X) == 1 and int(X[0]) != 1:
        pass
    else:
        for num in X:
            D += int(num)**2
        print("%.3f" % D**0.5)
        D = 0

