def div_two_integers(m, n):
    res = 0
    while m > n:
        s, t, p = m, n, 1
        while s > (t<<1):
            p <<= 1
            t <<= 1
        res += p
        m-=t
    return res

if __name__ == "__main__":
    print(div_two_integers(10, 3))
    print(div_two_integers(12, 5))
    print(div_two_integers(18, 7))
