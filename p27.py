s = input()
op = 0
wc = 0

for c in s:
    if c == '(':
        if wc > op:
            wc -= op
            op = 0
        else:
            op -= wc
            wc = 0
            
        op += 1
    if c == ')':
        if op > 0:
            op -= 1
        elif wc > 0:
            wc -= 1
        else:
            print('Not ')
            break
    if c == '*':
        wc += 1

if wc < op:
    print('Not')

print('Correct')
