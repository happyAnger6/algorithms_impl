def bubble_sort(a):
    start, end = 0, len(a)-1
    is_exchange = False
    while start < end:
        i, j = start, end
        is_exchange = False
        while i < j:
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                is_exchange = True
            i+=1
        if not is_exchange:
            return
        end-=1

if __name__ == "__main__":
    import random
    a = [random.randrange(100) for _ in range(50)]
    print(a)
    bubble_sort(a)
    print(a)
