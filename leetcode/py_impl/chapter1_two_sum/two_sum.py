from collections import defaultdict

def two_sum(ary, target):
    ix_dct = defaultdict(lambda : None)
    for i, e in enumerate(ary):
        if ix_dct[target-e] is not None:
            return (ix_dct[target-e], i)
        ix_dct[e] = i

if __name__ == "__main__":
    ary = [2, 3, 7, 8, 9]
    print(two_sum(ary, 9))

