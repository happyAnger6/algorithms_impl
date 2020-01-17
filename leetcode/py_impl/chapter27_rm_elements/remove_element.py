def remove_element(a, target):
    new_last = 0
    for i, e in enumerate(a):
        if e != target:
            a[new_last] = e
            new_last+=1
    return a[:new_last]

if __name__ == "__main__":
    print(remove_element([3,2,2,1,3,3], 3))
    print(remove_element([3,3,2,1,3,3], 3))
    print(remove_element([1,1,2,1,2,2], 2))
