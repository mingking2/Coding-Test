import sys
sys.setrecursionlimit(10**6)

def dfs(y, x, cnt):
    matrix[y][x] = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0<=ny<n and 0<=nx<m:
            if matrix[ny][nx] == 1:
                cnt = dfs(ny,nx,cnt+1)
    return cnt


n, m, k = map(int, sys.stdin.readline().split())

matrix = [[0 for _ in range(m)] for _ in range(n)]

for i in range(k):
    r, c = map(int, sys.stdin.readline().split())
    matrix[r - 1][c - 1] = 1

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]



num = 0
for i in range(n):
    for j in range(m):
        if matrix[i][j] == 1:
            num = max(num, dfs(i,j,1))



print(num)