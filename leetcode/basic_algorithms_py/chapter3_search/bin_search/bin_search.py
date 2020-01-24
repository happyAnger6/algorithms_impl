def bin_search(a, target):
    low, high = 0, len(a)-1
    while low <= high:
        mid = low + (high - low) // 2
        if a[mid] == target:
            return mid
        elif a[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return None

if __name__ == "__main__":
    import random
    a = [ random.randrange(50) for _ in range(50)]
    print(a)
    new_a = sorted(a)
    print(new_a)
    print(bin_search(a, 45))
