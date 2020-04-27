s = input()
r = input()

mismatches = []
miss = False

for i in range(len(s)):
    if not miss and s[i] != r[i]:
        mismatches.append([i, -1])
        miss = not miss
    elif miss and s[i] == r[i]:
        mismatches[-1][1] = i - 1;
        miss = not miss

    if miss:
        mismatches[-1][1] = len(s) - 1
        
print(mismatches)

while True:
    min_cost = len(mismatches) * sum(map(lambda x: x[1] - x[0] + 1, mismatches))
    to_delete = -1
    
    for i in range(len(mismatches) - 1):
        new_cost = ((min_cost / len(mismatches)) + mismatches[i+1][0] - mismatches[i][1]) * (len(mismatches) - 1)
        if new_cost < min_cost:
            to_delete = i

    if to_delete == -1:
        break
    else:
        mismatches[i][1] = mismatches[i+1][1]
        del mismatches[i+1]

print(mismatches)
print(len(mismatches) * sum(map(lambda x: x[1] - x[0] + 1, mismatches)))
