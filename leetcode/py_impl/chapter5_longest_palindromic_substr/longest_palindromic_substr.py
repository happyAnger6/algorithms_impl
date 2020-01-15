def search_longest(s, left, right, maxlen, lstart):
    step = 1
    start = lstart
    while left-step>=0 and right+step < len(s) and s[left-step] == s[right+step]:
        step+=1
    if right-left-1+2*step > maxlen:
        maxlen = right-left-1+2*step
        start = left - step + 1
    return maxlen, start


def longest_palindromic_substr(s):
    maxlen, start = 0, 0
    for i in range(len(s)-1):
        if s[i] == s[i+1]:
            left = i
            right = i + 1
            maxlen, start = search_longest(s, left, right, maxlen, start)
        left, right = i, i
        maxlen, start = search_longest(s, left, right, maxlen, start)
    end = start + maxlen
    if 0 == maxlen:
        end = len(s)
    return s[start:end]

if __name__ == "__main__":
    print(longest_palindromic_substr("abacd"))
    print(longest_palindromic_substr("dbaca"))
    print(longest_palindromic_substr("a"))
