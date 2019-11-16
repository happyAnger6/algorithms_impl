from array import array

class Bitmap:
    def __init__(self, maxvalue):
        bits = (maxvalue>>3)
        self.bitmap = array('B', (0 for _ in range(bits)))

    def set(self, v):
        bit = (v>>3)
        ibit = 1<<(v%8)
        self.bitmap[bit] |= ibit

    def is_set(self, v):
        bit = (v>>3)
        ibit = 1<<(v%8)
        return self.bitmap[bit] & ibit

if __name__ == "__main__":
    b = Bitmap(1000)
    for i in range(10):
        b.set(i)

    for i in range(20):
        print(b.is_set(i))
