import sys

def dfs(y,x,cnt,color):
    visited[y][x] = True
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0<=ny<m and 0<=nx<n:
            if not visited[ny][nx] and matrix[ny][nx] == color:
                cnt = dfs(ny, nx, cnt + 1, color)
    return cnt



n, m = map(int, sys.stdin.readline().split())

# 나머지 줄에서 문자열 행렬을 읽어들이기
matrix = [sys.stdin.readline().strip() for _ in range(m)]
visited = [[False for _ in range(n)] for _ in range(m)]



dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

white = 0
blue = 0
for i in range(m):
    for j in range(n):
        if matrix[i][j] == 'W' and not visited[i][j]:
            white += (dfs(i,j,1,'W')) ** 2
        elif matrix[i][j] == 'B' and not visited[i][j]:
            blue += (dfs(i, j, 1, 'B')) ** 2

print(white, blue)