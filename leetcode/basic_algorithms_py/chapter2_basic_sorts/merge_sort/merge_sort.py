def merge(a, start, mid, end):
    i, j = start, mid+1
    while i <= end and j <= end:
        if a[j] < a[i]:
            tmp = a[j]
            head, tail = i, j
            while tail > head:
                a[tail] = a[tail-1]
                tail -= 1
            a[head] = tmp
            j += 1
        i+=1

def merge_sort(a, start, end):
    if start >= end:
        return

    mid = start + (end - start) // 2
    merge_sort(a, start, mid)
    merge_sort(a, mid+1, end)
    merge(a, start, mid, end)

if __name__ == "__main__":
    import random
    l = [ random.randrange(10) for _ in range(10) ]
    print(l)
    merge_sort(l, 0, len(l) - 1)
    print(l)
