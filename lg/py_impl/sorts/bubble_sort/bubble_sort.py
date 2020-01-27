def bubble_sort(a):
    n = len(a)
    while n > 1:
        is_exchg = False
        for i in range(n-1):
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                is_exchg = True
        if not is_exchg:
            break
        n -= 1
