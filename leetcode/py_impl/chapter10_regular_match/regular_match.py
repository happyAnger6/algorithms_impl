def regular_match(s, p):
    if len(p) == 0:
        return len(s) == 0

    if len(p) == 1:
        return len(s) == 1 and (s[0] == p[0] or p[0] == '.')

    if p[1] != '*':
        if len(s) > 0 and (s[0] == p[0] or p[0] == '.'):
            return regular_match(s[1:], p[1:])
        else:
            return False

    while len(s) > 0 and (s[0] == p[0] or p[0] == '.'):
        if regular_match(s, p[2:]): #This is a least match.
            return True
        s = s[1:]

    return regular_match(s, p[2:])

if __name__ == "__main__":
    print(regular_match("aa", "a"))
    print(regular_match("aa", "aa"))
    print(regular_match("aaa", "aa"))
    print(regular_match("aa", "a*"))
    print(regular_match("aa", ".*"))
    print(regular_match("ab", ".*"))
    print(regular_match("aab", "c*a*b"))
