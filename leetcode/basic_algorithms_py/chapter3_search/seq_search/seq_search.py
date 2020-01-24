def seq_search(a, target):
    for i, e in enumerate(a):
        if e == target:
            return i
    return None

if __name__ == "__main__":
    import random
    l  = [ random.randrange(50) for _ in range(50) ]
    print(l)
    print(seq_search(l, 46))