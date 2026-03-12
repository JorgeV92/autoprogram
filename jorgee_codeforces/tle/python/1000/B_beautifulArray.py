t = int(input())
while t:
    n, k, b, s = map(int, input().split())
    a = [0]*n
    a[0] = k * b
    s -= k * b
    if (s < 0):
        print("-1")
    else:
        for i in range(n):
            now = min(k-1, s)
            a[i] += now
            s -= now
        if (s > 0):
            print("-1")
        else:
            for x in a:
                print(x, end=' ')
            print()
    t -= 1


