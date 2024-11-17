import sys 
N,K = map(int, sys.stdin.readline().split())
coins = list()
for _ in range(0,N):
    coins.append(int(sys.stdin.readline()))

# 0을 만드는법은 안쓰는법 -> 1가지
results = [0 for _ in range(K+1)]
results[0] = 1
for i in coins:
    for j in range(i,len(results)):
        if j-i>=0:
            results[j]+=results[j-i]
            
print(results[K])