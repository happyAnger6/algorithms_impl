def three_sum_closet(a, target):
    s_a = sorted(a)
    sum = s_a[0] + s_a[1] + s_a[2]
    diff = abs(sum - target)
    n = len(a)
    for i in range(n-2):
        left, right = i + 1, n - 1
        sum = s_a[i] + s_a[left] + s_a[right]
        newdiff = abs(sum - target)
        while left < right:
            if newdiff < diff:
                diff = newdiff
                closet = sum

            if sum < target:
                left+=1
            else:
                right-=1
    return closet

