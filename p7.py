s = "acccbaaacccbaac"
right = 1
left = 0
next_best = right
latest_next_best = False
n = len(s)
while right < n:

    if s[left] == s[right]:
        left += 1
        if s[right] == s[0] and not latest_next_best:
            next_best = right
            latest_next_best = True
        right += 1
    else:
        if right == n-1:
            break
        if latest_next_best:
            left = 1
            right = next_best + 1
            latest_next_best = False
        else:
            left = 0
            right += 1
            latest_next_best = False

print(s[:left])
