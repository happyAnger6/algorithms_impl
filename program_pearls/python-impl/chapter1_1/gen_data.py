from array import array
import random

N=10**7
FILENAME='ints.bin'
def gen_datafile(n):
    iarray = array('i', (random.randrange(n) for i in range(n)))
    with open(FILENAME, 'wb') as fp:
        iarray.tofile(fp)

def read_datafile(n):
    iarray = array('i')
    with open(FILENAME, 'rb') as fp:
        iarray.fromfile(fp, N)
    for i in range(n):
        print(iarray[i])


if __name__ == "__main__":
    gen_datafile(N)
    read_datafile(10)
