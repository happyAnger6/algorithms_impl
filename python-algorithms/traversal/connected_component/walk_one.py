from traversal.graphs import G, a

def walk_one(G, s):
    P, Q = dict(), []
    S = set()
    Q.append(s)
    S.add(s)
    while Q:
        n = Q.pop()
        for u in G[n]:
            if u in S: continue
            Q.append(u)
            S.add(u)
    P[s] = S
    return P

if __name__ == "__main__":
    print(walk_one(G, a))