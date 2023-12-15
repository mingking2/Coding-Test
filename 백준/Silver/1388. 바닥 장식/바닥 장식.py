import sys

sys.setrecursionlimit(10 ** 6)


def dfs(y, x, shape, diry, dirx):
    matrix[y][x] = '0'
    for i in range(2):
        ny = y + diry[i]
        nx = x + dirx[i]
        if 0 <= ny < n and 0 <= nx < m:
            if matrix[ny][nx] == shape:
                matrix[ny][nx] = '0'
                dfs(ny, nx, shape, diry, dirx)


n, m = map(int, sys.stdin.readline().split())
matrix = [['0' for j in range(m)] for i in range(n)]

for i in range(n):
    matrix[i] = list(sys.stdin.readline().strip())

count1 = 0
count2 = 0
for i in range(n):
    for j in range(m):
        if matrix[i][j] == "-":
            dyy = [0, 0]
            dyx = [-1, 1]
            dfs(i, j, '-', dyy, dyx)
            count1 += 1
        elif matrix[i][j] == "|":
            dxy = [-1, 1]
            dxx = [0, 0]
            dfs(i, j, '|', dxy, dxx)
            count2 += 1


# for i in range(n):
#     for j in range(m):
#         print(matrix[i][j], end="")
#     print()
#
# print(count1)
# print(count2)
print(count1 + count2)
