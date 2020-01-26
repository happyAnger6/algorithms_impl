from _collections import deque,defaultdict

class Heap:
    def __init__(self, iter):
        self.datas = deque()
        self.datas.extend(iter)
        self._shift()

    def add_data(self, iter_data):
        for e in iter_data:
            self.datas.append(e)
            self._shift_up(len(self.datas)-1)

    def output(self):
        output_level = defaultdict(str)
        total_pos = 0

        def draw_node(i, level):
            nonlocal total_pos
            if i >= len(self.datas):
                return 0
            ln = draw_node(2*i+1, level+1)
            ol_str = output_level[level]
            for k in range(total_pos-len(ol_str)):
                ol_str += ' '
            ol_str += str(self.datas[i])
            output_level[level] = ol_str
            total_pos += 2
            rn = draw_node(2*i+2, level+1)
            return ln + rn + 1

        draw_node(0, 0)
        for k, v in sorted(output_level.items(), key = lambda e: e[0]):
            print(v)

    def seq_output(self):
        while self.datas:
            print(self.datas[0])
            self.datas[0] = self.datas[-1]
            self.datas.pop()
            self._shift_down(0)

    def _shift(self):
        n = len(self.datas)
        last = (n - 1) // 2
        while last >= 0:
            self._shift_down(last)
            last -= 1

    def _shift_up(self, pos):
        n = len(self.datas)
        if pos >= n:
            return

        a = self.datas
        while pos > 0:
            father = 0
            if 0 == pos%2:
                father = (pos-2)//2
            else:
                father = (pos-1)//2
            if a[father] > a[pos]:
                a[father], a[pos] = a[pos], a[father]
                pos = father
            else:
                break


    def _shift_down(self, pos):
        n = len(self.datas)
        if pos >= n:
            return

        a = self.datas
        while pos < n:
            left = pos * 2 + 1
            right = pos * 2 + 2
            exchg = None
            min_num = a[pos]
            if left < n and a[left] < min_num:
                min_num = a[left]
                exchg = left
            if right < n and a[right] < min_num:
                min_num = a[right]
                exchg = right

            if exchg is None:
                break
            a[pos], a[exchg] = a[exchg], a[pos]
            pos = exchg

if __name__ == "__main__":
    import random
    a = [random.randrange(30) for _ in range(50)]
    print(a)
    heap = Heap(a)
    heap.output()
    print(heap.datas)
    heap.add_data([6,9,25])
    print(heap.datas)
    heap.output()
