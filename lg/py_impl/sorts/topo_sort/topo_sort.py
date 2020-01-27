class Graph:
    def __init__(self, n):
        self.nodes = []
        for i in range(n):
            self.nodes.append(Node(i))

    def add_edge(self, start, end):
        s = self.nodes[start]
        e = self.nodes[end]
        e.degree += 1
        s.edges.add(e)


class Node:
    def __init__(self, data):
        self.data = data
        self.degree = 0
        self.edges = set()

def topo_sort(g):
    res = []
    q = []
    for n in g.nodes:
        if n.degree == 0:
            q.append(n)
    while q:
        t = q.pop()
        res.append(t)
        for v in t.edges:
            v.degree -= 1
            if v.degree == 0:
                q.append(v)
    return res

