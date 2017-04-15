#This implementation doesn't detect invalid input
import sys

def is_higher_prec(op, stack_top):
    if (op == '+') and (
        stack_top == '*' or stack_top == '+'):
        return True
    elif op == '*' and stack_top == '*':
        return True
    else:
        return False

for line in sys.stdin:
    oprs = []
    post_exp = []
    for token in line:
        if token.isdigit():
            post_exp.append(token)
        else:
            if token == " " or token == "\n":
                pass
            elif token == ')':
                while oprs[-1] != '(':
                    post_exp.append(oprs[-1])
                    del oprs[-1]
                del oprs[-1]
            else:
                while len(oprs) and oprs[-1] != '(' and is_higher_prec(token, oprs[-1]):
                    # len(oprs) to prevent oprs[-1] out of range
                    post_exp.append(oprs[-1])
                    del oprs[-1]
                oprs.append(token)
    else:
        post_exp.extend(oprs[::-1])
        #"pop"(i.e. oprs[::-1]) ramaing operators in the stack
    L = []
    result = 0
    for token in post_exp:
        if token.isdigit():
            L.append(int(token))
        else:
            if token == '+':
                L[-2] = L[-2] + L[-1]
            else: # '*'
                L[-2] = L[-2] * L[-1]
            del L[-1]
                # operand<1> operand<2> operator --> operand, del last element
    print(L[0]%1000000007)
    
    
