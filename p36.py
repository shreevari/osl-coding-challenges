def choose(cards, k):
    if k == 0:
        return 0
    else:
        return max(cards[0] + choose(cards[1:], k-1), cards[-1] + choose(cards[:-1], k-1))

print(choose([1, 2,3, 4, 5, 6, 1], 3))
print(choose([2, 3, 1, 1, 2, 4], 3))
