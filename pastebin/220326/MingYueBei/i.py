import sys

input=sys.stdin.readline
print=sys.stdout.write

p=998244353
fac=[]
inv=[]

def dfs(u,G,sz):
    global p
    sz[u]+=1
    A=[]
    ret=1
    for v in G[u]:
        ret*=dfs(v,G,sz)
        sz[u]+=sz[v]
        A.append(sz[v])
    ret=fac[n-1]
    for x in A:
        ret*=inv[x]
    return ret


def main():
    n=int(input())
    A=tuple(map(int,input().split()))
    G=[[]for i in range(n+1)]
    sz=[0 for i in range(n+1)]
    fac=[0 for i in range(n+1)]
    inv=[0 for i in range(n+1)]
    for i in range(n-1):
        G[A[i]].append(i+2)
    fac[0]=1
    for i in range(1,n+1):
        fac[i]=fac[i-1]*i%p
    x=fac[n]
    y=p-2
    ans=1
    while y:
        if (y&1)!=0:
            ans=ans*x%p
        y>>=1
        x=x*x%p
    inv[n]=ans
    for i in range(n-1,-1,-1):
        inv[i]=inv[i+1]*(i+1)%p
    print("{}\n".format(dfs(1,G,n,sz)))
     
    

if __name__=='__main__':
    main()
