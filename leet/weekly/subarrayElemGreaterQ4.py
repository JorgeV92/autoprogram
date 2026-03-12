from typing import List
            

class Solution:
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        def find(x):
            if x == p[x]:
                return x
            p[x] = find(p[x])
            return p[x]

        def unite(x, y):
            x = find(x); y = find(y)
            if x == y:
                return False
            if sz[x] < sz[y]:
                x, y = y, x
            sz[x] += sz[y]
            p[y] = x
        
        n = len(nums)
        p = [i for i in range(n)]
        sz = [1] * n
        arr = [(x, i) for i, x in enumerate(nums)]
        arr.sort(reverse=True)
        vis = [False]*n
        for j in range(n):
            v = arr[j][0]; i = arr[j][1]
            if i and vis[i-1]:
                unite(i, i-1)
            if i < n-1 and vis[i+1]:
                unite(i, i+1)
            if v > (threshold // sz[find(i)]):
                return sz[find(i)]
            vis[i] = True
        return -1
    

