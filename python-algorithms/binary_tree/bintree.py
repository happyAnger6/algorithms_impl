class BinNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

class BinTree:
    def __init__(self, data=None):
        if data is None:
            self.root = None
        else:
            self.root = BinNode(data)

    def add_data(self, data):
        if self.root is None:
            self.root = BinNode(data)
        else:
            p = self.root
            while True:
                if data < p.data:
                    p = p.left
                    if p is None:
                        p.left = BinNode(data)
                        break
                else:
                    p = p.right
                    if p is None:
                        p.right = BinNode(data)
                        break
