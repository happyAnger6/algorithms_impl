a, b, c, d, e, f = range(6)

G = [
    {b, c},
    {a, c, d, e},
    {a, b, f},
    {b},
    {b, f},
    {c, e},
]

def iddfs(G, s):
    yielded = set()
    def depth_dfs(G, s, d, S=None):
        if s not in yielded:
            yielded.add(s)
            yield s
        if S is None: S = set()
        if d == 0: return
        S.add(s)
        for v in G[s]:
            if v in S: continue
            yield depth_dfs(G, v, d-1, S)
    for d in range(len(G)):
        if len(yielded) == len(G): break
        for v in depth_dfs(G, s, d):
            yield v

