def str2int(s):
    n = len(s)
    i = 0
    if n == 0:
        return 0
    while i < n and s[i] == ' ':
        i+=1

    sign = 1
    if s[i] == '+' or s[i] == '-':
        if s[i] == '-':
            sign = -1
        i+=1
    res = 0
    while i < n:
        res = res*10+ (ord(s[i]) - ord('0'))
        i+=1
    return res*sign

if __name__ == "__main__":
    print(str2int('-123'))
    print(str2int('-3214'))
    print(str2int('  -100'))
    print(str2int('  -0'))
    print(str2int(''))
    print(str2int('  123123123123123123123'))


