import sys
import math
from collections import Counter

input=sys.stdin.readline
print=sys.stdout.write

def main():
    n,k,x=map(int,input().split())
    A=list(map(int,input().split()))
    for i in range(n):
        if A[i]//x<=k:
            k-=A[i]//x
            A[i]%=x
        else:
            A[i]-=k*x
            k=0
    A.sort(key=lambda x:-x)
    for i in range(min(n,k)):
        A[i]=0
    print(f'{sum(A)}\n')


if __name__=='__main__':
    main()