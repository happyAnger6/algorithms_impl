
def dp_longest_palindromic_substr(s):
    n = len(s)
    dp = [[0 for _ in range(n)] for _ in range(n)]
    start, slen = 0, 1
    for i in range(n):
        for j in range(i):
            dp[j][i] = (s[i] == s[j] and (dp[j+1][i-1]) or i - j < 2)
            if dp[j][i]:
                if i - j + 1 > slen:
                    slen = i - j + 1
                    start = j
        dp[i][i] = 1
    return s[start: start+slen]



if __name__ == "__main__":
    print(dp_longest_palindromic_substr("abacd"))
    print(dp_longest_palindromic_substr("dbaca"))
    print(dp_longest_palindromic_substr("a"))
