import sys
import heapq

input=sys.stdin.readline
print=sys.stdout.write

def main():
    n,m=map(int,input().split())
    A=[tuple(map(int,input().split())) for _ in range(m)]
    G=[[]for i in range(n+2)]
    for i in range(2,n+1):
        G[i].append((i-1,1))
    for l,r in A:
        G[l].append((r+1,r-l+1))
    dis=[0x3f3f3f3f for i in range(n+2)]
    dis[1]=0
    q=[(0,1)]
    while q:
        cur=heapq.heappop(q)
        u=cur[1]
        if dis[u]!=cur[0]:
            continue
        for v,d in G[u]:
            if dis[v]>dis[u]+d:
                dis[v]=dis[u]+d
                heapq.heappush(q,(dis[v],v))
    print("{}\n".format(-1 if dis[n+1]==0x3f3f3f3f else (dis[n+1]-n)//2))


if __name__=='__main__':
    main()