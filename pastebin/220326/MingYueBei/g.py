import sys

input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(20000000)

def dfs(u,f,G,leaf,dis):
    has_son=False
    for v,d in G[u]:
        if v==f:
            continue
        has_son=True
        dis[v]=dis[u]+d
        dfs(v,u,G,leaf,dis)
    if not has_son:
        leaf[u]=True

def main():
    n=int(input())
    G=[[]for i in range(n+1)]
    leaf=[False for i in range(n+1)]
    dis=[0 for i in range(n+1)]
    for _ in range(n-1):
        u,v,d=map(int,input().split())
        G[u].append((v,d))
        G[v].append((u,d))
    dfs(1,1,G,leaf,dis)
    A=[]
    for i in range(1,n+1):
        if leaf[i]:
            A.append(dis[i])
    A.sort()
    n=len(A)
    c=[0 for i in range(n)]
    m=int(input())
    for _ in range(m):
        s=int(input())
        l,r=-1,n
        while l+1<r:
            mid=(l+r)//2
            if(A[mid]<=s):
                l=mid
            else:
                r=mid
        if l>=0:
            c[l]+=1
    for i in range(n-2,-1,-1):
        c[i]+=c[i+1]
    ans=c[n-1]
    for i in range(n-1):
        ans=min(ans,c[i]//(n-i))
    print("{}\n".format(ans))


if __name__=='__main__':
    main()


''''

5
1 2 2
1 4 1
3 4 2
5 4 3
8
2
4
3
6
7
1
8
9

''''