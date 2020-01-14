def find_kth(a1, i, a2, j, k):
    if len(a1) - i > len(a2) - j:
        return find_kth(a2, j, a1, i, k)

    if i == len(a1):
        return a2[j + k + 1]

    if 1 == k:
        if a1[i] < a2[j]:
            return a1[i]
        else:
            return a2[j]

    pa = min(i+k//2, len(a1))
    pb = j + k - pa + i
    if a1[pa-1] < a2[pb-1]:
        return find_kth(a1, pa, a2, j, k-pa+i)
    else:
        return find_kth(a1, i, a2, pb, k-pb+j)

def find_mid_of_two_sorted_arys(a1, a2):
    n = len(a1)
    m = len(a2)
    total = m + n
    if total % 2 == 0:
        return find_kth(a1, 0, a2, 0, total/2) + find_kth(a1, 0, a2, 0, total/2+1)
    else:
        return find_kth(a1, 0, a2, 0, total/2)