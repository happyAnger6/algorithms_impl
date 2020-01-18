def four_sum(a, target):
    res = []
    n = len(a)
    if n < 4:
        return res

    for i in range(n-4):
        if i > 0 and a[i] == a[i-1]:
            continue
        for j in range(i+1, n-3):
            if j > i+1 and a[j] == a[j-1]:
                continue
            left, right = j+1, n-1
            while left < right:
                sum = a[i] + a[j] + a[left] + a[right]
                if sum == target:
                    res.append((a[i], a[j], a[left], a[right]))
                    if left+1 < n-1 and a[left+1] == a[left]:
                        left+=1
                    if right > left  and a[right-1] == a[right]:
                        right-=1
                    left+=1
                    right-=1
                elif sum < target:
                    left+=1
                else:
                    right-=1
    return res

if __name__ == "__main__":
    print(four_sum([1,1,2,2,3,3,4,4], 10))