n, d = map(int, input().split())
p = [int(x) for x in input().split()] # list(map(int, input.split()))
p.sort(reverse=True)
ans = 0 
r = n-1
for l in range(n):
    t = d // p[l] + 1
    if r - l < t:
        break
    r -= t - 1
    ans += 1
print(ans)