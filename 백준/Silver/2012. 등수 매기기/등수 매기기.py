import sys
n = int(sys.stdin.readline())
test = []


for _ in range(n):
    test.append(int(sys.stdin.readline()))

test.sort()

result = 0
for i in range(1, n+1):
    result += abs(i-test[i-1])

print(result)



