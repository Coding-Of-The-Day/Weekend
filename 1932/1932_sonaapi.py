import sys


def solution():
    N = int(sys.stdin.readline())
    triangle = list()
    for _ in range(N):
        triangle.append(list(map(int, sys.stdin.readline().split())))

    triangle.reverse()
    idx = 0

    while 1:
        if idx > len(triangle) - 2:
            break
        for i in range(len(triangle[idx])-1):
            triangle[idx+1][i] += max(triangle[idx][i],triangle[idx][i+1])

        idx += 1
    print(triangle[len(triangle)-1][0])

solution()
