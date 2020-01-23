def partition(a, start, end):
    guard = a[end]
    j = start
    for i in range(start, end):
        if a[i] <= guard:
            a[j], a[i] = a[i], a[j]
            j+=1
    a[j], a[end] = a[end], a[j]
    return j

def qsort(a, start, end):
    if start >= end:
        return
    mid = partition(a, start, end)
    qsort(a, start, mid-1)
    qsort(a, mid+1, end)

if __name__ == "__main__":
    import random
    a = [random.randrange(1, 30) for _ in range(30)]
    print(a)
    qsort(a, 0, len(a)-1)
    print(a)
