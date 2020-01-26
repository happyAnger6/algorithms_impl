from collections import deque

class TreeNode:
    def __init__(self, char):
        self.char = char
        self.ends = 0
        self.children = []

    def add_child(self, char, isEnd=False):
        added = None
        for c in self.children:
            if c.char == char:
                added = c
                break
        if added is None:
            added = TreeNode(char)
            self.children.append(added)
        if isEnd:
            added.ends += 1
        return added

class PrefixTree:
    def __init__(self):
        self.root = TreeNode(None)

    def add_char(self, char):
        return self.root.add_child(char)

    def add_str(self, _str):
        cur_node = self.root
        isEnd = False
        for i, c in enumerate(_str):
            if i == len(_str) - 1:
                isEnd = True
            cur_node = cur_node.add_child(_str[:i+1], isEnd)

    def prt(self):
        q = deque()
        q.append(self.root)
        while q:
            t = q.popleft()
            print(t.char)
            for c in t.children:
                q.append(c)

    def find_all_prefix_strs(self, prefix):
        all_results = []
        def find_prefix_node(node, prefix, end):
            if end > len(prefix):
                return node
            for c in node.children:
                if c.char == prefix[:end]:
                    return find_prefix_node(c, prefix, end+1)
            return None
        node = find_prefix_node(self.root, prefix, 1)

        def find_node_strs(node):
            nonlocal all_results
            q = deque()
            q.append(node)
            while q:
                t = q.popleft()
                if t.ends > 0:
                    all_results.append(t.char)
                for c in t.children:
                    q.append(c)
        find_node_strs(node)
        return all_results




if __name__ == "__main__":
    strs = ['abc', 'ade', 'aaa', 'bcd', 'bbc', 'acff', 'acd', 'bbfa']
    pt = PrefixTree()
    for s in strs:
        pt.add_str(s)
    pt.prt()
    for c in pt.find_all_prefix_strs('bb'):
        print(c)