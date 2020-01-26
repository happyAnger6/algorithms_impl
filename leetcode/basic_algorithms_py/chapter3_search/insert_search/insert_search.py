def insert_search(a, target):
    low, high = 0, len(a) - 1
    while low <= high:
        mid = (target - a[low]) // (a[high] - a[low]) * (high - low)
        if mid  == low:
            mid += 1
