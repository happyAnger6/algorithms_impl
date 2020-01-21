class Graph:
    def __init__(self, n):
        self.nodes = []
        for i in range(n):
            self.nodes.append(Node(i))

    def add_edge(self, start, end):
        start_n = self.nodes[start]
        start_e = self.nodes[end]
        start_n.add_edge(start_e)
        start_e.add_edge(start_n)

    def prt(self):
        from collections import deque
        q = deque()
        q.append(self.nodes[0])
        seen = set()
        seen.add(self.nodes[0])
        while q:
            n = q.popleft()
            print(n)
            for c in n.adjacent:
                if c not in seen:
                    seen.add(c)
                    q.append(c)

    def bfs(self, f=None):
        print('------bfs------')
        from collections import deque
        q = deque()
        q.append(self.nodes[0])
        seen = set()
        seen.add(self.nodes[0])
        def dfs_color(n, color=None):
            def draw_node(n, draw_color):
                if n.color is None:
                    n.color = draw_color
                else:
                    if n.color != draw_color:
                        return None

                if n.color == 0:
                    return 1
                else:
                    return 0

            if color is None:
                next_color = draw_node(n, 1)
            else:
                next_color = draw_node(n, color)

            if next_color is None:
                return False

            if not n.adjacent:
                return True
            return dfs_color(n.adjacent[0], next_color)

        while q:
            n = q.popleft()
            f(n)
            for c in n.adjacent:
                if c not in seen:
                    seen.add(c)
                    q.append(c)
        print('------bfs------')

    def dfs(self):
        print('------dfs------')
        from collections import deque
        q, seen = deque(), set()
        q.append(self.nodes[0])
        seen.add(self.nodes[0])
        while q:
            n = q.pop()
            n.prt()
            for c in n.adjacent:
                if c not in seen:
                    seen.add(c)
                    q.append(c)
        print('------dfs------')


class Node:
    def __init__(self, n):
        self.data = n
        self.adjacent = set()
        self.color = None

    def set_color(self, color):
        self.color = color

    def add_edge(self, node):
        self.adjacent.add(node)

    def prt(self):
        print(self.data)

    def __str__(self):
        s = '%d' % self.data
        for c in self.adjacent:
            s += '--->%d' % c.data
        return s

if __name__ == "__main__":
    g = Graph(5)
    g.add_edge(0, 1)
    g.add_edge(0, 4)
    g.add_edge(1, 3)
    g.add_edge(4, 2)
    g.add_edge(3, 2)
    g.prt()
    g.bfs(lambda x: x.prt())
    g.dfs()

