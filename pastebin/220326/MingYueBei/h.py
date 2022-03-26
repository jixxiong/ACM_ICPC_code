import sys

input=sys.stdin.readline
print=sys.stdout.write

def main():
    n=int(input())
    A=[tuple(map(int,input().split())) for _ in range(n)]
    ret=-1
    for i in range(1<<n):
        lz,rz=0,n
        lj,rj=0,n
        c=0
        for j in range(n):
            if ((i>>j)&1)!=0:
                c+=1
                if A[j][0]==1:
                    lz=max(lz,A[j][1])
                if A[j][0]==2:
                    rz=min(rz,A[j][1])
                if A[j][0]==3:
                    lj=max(lj,A[j][1])
                if A[j][0]==4:
                    rj=min(rj,A[j][1])
            else:
                if A[j][0]==1:
                    rz=min(rz,A[j][1]-1)
                if A[j][0]==2:
                    lz=max(lz,A[j][1]+1)
                if A[j][0]==3:
                    rj=min(rj,A[j][1]-1)
                if A[j][0]==4:
                    lj=max(lj,A[j][1]+1)
        if not ((c>=lz and c<=rz) and ((n-c)>=lj and (n-c)<=rj)):
            continue
        ret=max(ret,c)
    print("{}\n".format(ret))


if __name__=='__main__':
    main()
