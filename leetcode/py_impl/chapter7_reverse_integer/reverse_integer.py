def reverse_integer(num):
    positive = 0
    if num < 0:
        positive = 1
        num = -num

    res = 0
    while num > 0:
        res = res*10 + num%10
        num = num//10
    if positive == 0:
        return res
    return -res

if __name__ == "__main__":
    print(reverse_integer(123))
    print(reverse_integer(321))
    print(reverse_integer(-123))
