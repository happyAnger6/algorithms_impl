def find_first_lt(a, target):
    low, high = 0, len(a) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if a[mid] == target:
            high = mid - 1
        elif a[mid] < target:
            if mid == high or a[mid+1] >= target:
                return mid
            else:
                low = mid + 1
        else:
            high = mid - 1
    return None

if __name__ == "__main__":
    import random
    l = sorted([ random.randrange(10) for _ in range(10)])
    print(l)
    print(find_first_lt(l, 6))