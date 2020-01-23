def insert_sort(a):
    n = len(a)
    for i in range(1, n):
        for j in range(0, i+1):
            if a[j] > a[i]:
                break
        k, tmp = i, a[i]
        while k > j:
            a[k] = a[k-1]
            k-=1
        a[j] = tmp

if __name__ == "__main__":
    import random
    a = [random.randrange(1,30) for _ in range(50)]
    print(a)
    insert_sort(a)
    print(a)


