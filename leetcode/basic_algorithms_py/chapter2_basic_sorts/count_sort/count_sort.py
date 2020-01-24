def count_sort(a):
    max_num = max(a)
    cnt_ary = [0 for _ in range(max_num+1)]
    for e in a:
        cnt_ary[e]+=1

    j = 0
    for i, cnt in enumerate(cnt_ary):
        while cnt > 0:
            a[j] = i
            j+=1
            cnt-=1


if __name__ == "__main__":
    import random
    l = [ random.randrange(5) for _ in range(10)]
    print(l)
    count_sort(l)
    print(l)
