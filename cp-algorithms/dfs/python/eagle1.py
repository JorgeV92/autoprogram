def dfs(u, p, d, i, adj, dist):
    dist[i][u] = d
    opt = -1
    for v, w in adj[u]:
        if v != p:
            x = dfs(v, u, d + w, i, adj, dist)
            if opt == -1 or dist[i][x] > dist[i][opt]:
                opt = x
    return u if opt == -1 else opt

def solve():
    n = int(input())
    g = [[] for _ in range(n+1)]
    dist = [[0]*(n+1) for _ in range(2)]
    for _ in range(n-1):
        u, v, w = map(int, input().split())
        g[u].append((v, w))
        g[v].append((u, w))

    nodeA = dfs(1, 0, 0, 0, g, dist)
    nodeB = dfs(nodeA, 0, 0 , 0, g, dist)
    dfs(nodeB, 0, 0, 1, g, dist)
    print(" ".join(str(max(dist[0][i], dist[1][i])) for i in range(1, n+1)))
    

def main():
    t = int(input())
    while t:
        solve()
        t -=1

main()