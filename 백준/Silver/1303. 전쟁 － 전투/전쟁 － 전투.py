import sys


def dfs(x, y, cnt, color):
    matrix[x][y] = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < m and 0 <= ny < n:
            if matrix[nx][ny] == color:
                cnt = dfs(nx, ny, cnt + 1, color)
    return cnt


# 두 정수를 공백으로 구분하여 입력받기
n, m = map(int, input().split())

# 나머지 줄에서 문자열 행렬을 읽어들이기
matrix = [list(input()) for _ in range(m)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

white = 0
blue = 0
for i in range(m):
    for j in range(n):
        if matrix[i][j] == 'W':
            white += (dfs(i, j, 1, 'W')) ** 2
        elif matrix[i][j] == 'B':
            blue += (dfs(i, j, 1, 'B')) ** 2

print(white, blue)
