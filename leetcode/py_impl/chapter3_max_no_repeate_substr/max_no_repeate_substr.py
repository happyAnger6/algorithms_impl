from collections import defaultdict

def max_no_repeate_substr(s):
    next_seen = defaultdict(lambda : 0)
    max_str = ''
    left, res = 0, 0
    for i in range(len(s)):
        c = s[i]
        if next_seen[c] == 0 or next_seen[c] < left:
            res = max(res, i - left + 1)
            max_str = s[left:i+1]
        else:
            left = next_seen[c]
        next_seen[c] = i + 1
    return max_str

if __name__ == "__main__":
    print(max_no_repeate_substr('abcad'))
    print(max_no_repeate_substr('bbbb'))
