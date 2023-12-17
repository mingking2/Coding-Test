import sys
sys.setrecursionlimit(10 ** 6)

def dfs(v):
    global cnt
    visited[v] = True
    answer[v] = cnt
    link[v].sort(reverse=True)
    for i in link[v]:
        if not visited[i]:
            cnt += 1
            dfs(i)


n, m, r = map(int, sys.stdin.readline().split())
link = [[] for _ in range(n+1)]
visited = [False]*(n+1)
answer = [0] * (n + 1)
cnt = 1

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    link[a].append(b)
    link[b].append(a)


dfs(r)

for i in answer[1:]:
    print(i)


