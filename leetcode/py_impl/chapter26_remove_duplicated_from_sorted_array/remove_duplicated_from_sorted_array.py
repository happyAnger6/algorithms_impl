def remove_duplicated_from_sorted_array(a):
    cur = a[0]
    n = len(a)
    for i in range(1, len(a)):
        if a[i] == cur:
            n-=1
        else:
            cur = a[i]
    return n

def remove_duplicated_from_sorted_array1(a):
    cur = None
    i = 0
    n = len(a)
    for j in range(len(a)):
        if cur is None or a[j] != cur:
            a[i] = a[j]
            i += 1
            cur = a[j]
    return i, a[:i]

if __name__ == "__main__":
    print(remove_duplicated_from_sorted_array([1,1,2,3,3,4,5,6,6,7]))
    print(remove_duplicated_from_sorted_array1([1,1,2,3,3,4,5,6,6,7]))
