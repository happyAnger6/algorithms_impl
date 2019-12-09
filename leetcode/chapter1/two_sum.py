from collections import defaultdict

def two_sum(a, n, target):
    sum_d = {}
    for i, e in enumerate(a):
        if sum_d.get(target-e, None):
            return (i, sum_d[target - e])
        else:
            sum_d[e] = i
    return (None, None)

if __name__ == "__main__":
    import random
    a = [random.randrange(100) for _ in range(100)]
    x, y = two_sum(a, len(a), 40)
    print(x, y, a[x], a[y])
