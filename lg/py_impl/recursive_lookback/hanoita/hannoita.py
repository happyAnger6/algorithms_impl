def hanoita(n, a, b, c):
    if n == 0:
        return
    hanoita(n-1, a, c, b)
    print('move %d from %s to %s' % (n, a, c))
    hanoita(n-1, b, a, c)

if __name__ == "__main__":
    hanoita(3, 'a', 'b', 'c')