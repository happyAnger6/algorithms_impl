def sel_sort(a):
    n = len(a)
    for i in range(n):
        min_i = i
        for j in range(i, n):
            if a[j] < a[min_i]:
                min_i = j
        a[i], a[min_i] = a[min_i], a[i]

if __name__ == "__main__":
    import random
    l = [random.randrange(50) for _ in range(50)]
    print(l)
    sel_sort(l)
    print(l)
