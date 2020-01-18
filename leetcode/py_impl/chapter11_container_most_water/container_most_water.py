def container_most_water(a):
    res = 0
    l, r = 0, len(a) - 1
    while l < r:
        res = max(res, min(a[l], a[r]) * (r - l))
        if a[l] < a[r]:
            l+=1
        else:
            r-=1
    return res

if __name__ == "__main__":
    a=[1,0,2,1,3,2,0]
    print(container_most_water(a))
