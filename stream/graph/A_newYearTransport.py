n, t = map(int, input().split())
a = [0] + list(map(int,input().split()))
cur = 1
valid = False
while cur < n:
    cur = cur + a[cur]
    if cur == t:
        valid = True
        break
if valid:
    print("YES")
else:
    print("NO")
        