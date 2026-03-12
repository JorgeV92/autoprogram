def main():
    N, M = map(int, input().split())
    g = [[] for _ in range(N+1)]
    cat = [0] + list(map(int, input().split()))
    for i in range(1, N):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    ans = 0

    def dfs(u: int, fa: int, cnt: int):
        nonlocal ans
        if cnt > M:
            return 
        is_leaf = True
        for v in g[u]:
            if v == fa:
                continue
            is_leaf = False
            c = cnt + 1 if cat[v] else 0
            dfs(v, u, c)
        ans += is_leaf

    dfs(1, 0, cat[1])
    print(ans)
        
main()
    


