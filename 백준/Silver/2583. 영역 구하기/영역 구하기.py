import sys

sys.setrecursionlimit(10 ** 6)


def dfs(y, x, cnt):
    matrix[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < m and 0 <= nx < n:
            if matrix[ny][nx] == 0:
                matrix[ny][nx] = 1
                cnt = dfs(ny, nx, cnt + 1)
    return cnt


m, n, k = map(int, sys.stdin.readline().split())
matrix = [[0 for _ in range(n)] for _ in range(m)]
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

for _ in range(k):
    a, b, c, d = map(int, sys.stdin.readline().split())
    for i in range(b, d):
        for j in range(a, c):
            matrix[i][j] = 1

# for i in range(m):
#     for j in range(n):
#         print(matrix[i][j], end=" ")
#     print()

cnt = 0
list = []
for i in range(m):
    for j in range(n):
        if matrix[i][j] == 0:
            cnt = dfs(i, j, 1)
            list.append(cnt)

list.sort()
print(len(list))
for i in range(len(list)):
    print(list[i], end=" ")
