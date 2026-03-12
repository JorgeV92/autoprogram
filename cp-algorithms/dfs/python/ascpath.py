def solve():
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1 , 0, 1, -1, 1, -1, 0, 1]

    t = 1
    while True:
        try:
            line = input().split()
        except EOFError:
            break
        if not line:
            continue
        
        N, M = map(int, line)
        if N == 0 and M == 0:
            break
        
        grid = [input().strip() for _ in range(N)]
        dp = [[-1] * M for _ in range(N)]

        def valid(r, c):
            return 0 <= r < N and 0 <= c < M
        
        def dfs(r, c):
            if dp[r][c] != -1:
                return dp[r][c]
            best = 1
            nxt = chr(ord(grid[r][c]) + 1)
            for k in range(8):
                nr = r + dx[k]
                nc = c + dy[k]
                if valid(nr, nc) and grid[nr][nc] == nxt:
                    best = max(best, 1 + dfs(nr, nc))
            dp[r][c] = best
            return best
        
        global_best = 0
        for i in range(N):
            for j in range(M):
                if grid[i][j] == 'A':
                    global_best = max(global_best, dfs(i, j))
        print(f"Case {t}: {global_best}")
        t += 1

solve()