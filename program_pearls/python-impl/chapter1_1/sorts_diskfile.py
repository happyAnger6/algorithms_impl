from array import array

N=10**7
MEM=((10**6)>>2)

def partition(ary, start, end):
    t = ary[end]
    pos = start
    for i in range(start, end):
        if ary[i] < t:
            ary[i], ary[pos] = ary[pos], ary[i]
            pos += 1
    ary[pos], ary[end] = ary[pos], ary[end]
    return pos

def quick_sort(ary, start, end):
    if start < end:
        mid = partition(ary, start, end)
        quick_sort(ary, start, mid)
        quick_sort(ary, mid+1, end)

def get_range(filename, start, end):
    oary = array('d')
    n=N
    with open(filename, 'rb') as fp:
        while n > 0:
            iarray = array('d')
            iarray.fromfile(fp, MEM)
            for i in iarray:
                if i >= start and i <= end:
                    oary.append(i)
            n-=MEM
    return oary

def sort_diskfile(ifilename, ofilename, n):
    with open(ofilename, 'rb') as ofp:
        n=0
        while n < N:
            sorted(get_range(ifilename, n, n+MEM-1)).tofile(ofilename)
            n+=MEM

