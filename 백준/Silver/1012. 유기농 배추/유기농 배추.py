import sys
sys.setrecursionlimit(10**6)

def dfs(y,x):
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < n and 0 <= nx < m:
            if matrix[ny][nx] == 1:
                matrix[ny][nx] = 0
                dfs(ny, nx)


t = int(sys.stdin.readline())
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]


for _ in range(t):
    m, n, k = map(int, sys.stdin.readline().split())
    matrix = [[0 for _ in range(m)] for _ in range(n)]
    count = 0
    for _ in range(k):
        x, y = map(int, sys.stdin.readline().split())
        matrix[y][x] = 1
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                dfs(i,j)
                count += 1

    print(count)
