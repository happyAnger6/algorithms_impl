def longest_prefix(strs):
    res = ''
    n = len(strs)
    if 0 == n:
        return res
    first_n = len(strs[0])
    for i in range(first_n):
        c = strs[0][i]
        for j in range(1, n):
            if len(strs[j]) < i+1 or strs[j][i] != c:
                return res
        res += c
    return res

if __name__ == "__main__":
    print(longest_prefix(['abc', 'ab', 'abcddd']))
    print(longest_prefix(['abc']))
