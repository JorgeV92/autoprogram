t = int(input())
while t:
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    mn = mx = a[0]
    ans = 0
    for i in range(n):
        mn = min(mn, a[i])
        mx = max(mx, a[i])
        if mx - mn > 2*x:
            ans += 1
            mn = mx = a[i]
    print(ans)
    t -= 1
