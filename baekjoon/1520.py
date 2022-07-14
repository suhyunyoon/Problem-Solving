import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

# input
m, n = list(map(int, input().split()))
arr = []
for i in range(m):
    arr.append(list(map(int, input().split())))

di = [-1, 1, 0, 0]
dj = [0, 0, -1, 1]
# arr[i][j] 칸에 대한 정답
dp = [[-1 for j in range(n)] for i in range(m)]
   
def dfs(i, j):
    # destination
    if i == m-1 and j == n-1:
        return 1
    # visited (memoization)
    if dp[i][j] != -1:
        return dp[i][j]
    
    dp[i][j] = 0
    for ddi, ddj in zip(di, dj):
        newi = i + ddi
        newj = j + ddj
        # dfs
        if 0 <= newi < m and 0 <= newj < n and arr[i][j] > arr[newi][newj]:
            dp[i][j] += dfs(i+ddi, j+ddj)
    return dp[i][j]

ans = dfs(0, 0)
print(ans)