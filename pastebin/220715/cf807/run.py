import sys
import os
import filecmp

assert(os.system("g++ d.cpp -o ./d -O2 -Wall -std=c++17")==0)
assert(os.system("g++ dd.cpp -o ./dd -O2 -Wall -std=c++17")==0)


for n in range(8,10):
    print(f'testing all possible input with length {n}: ',end='')

    cnt=0

    lst=[]

    def get(x):
        s=bin(x)[2:]
        s=(''.join(['0']*(n-len(s))))+s
        return s

    for S in range(1<<n):
        for T in range(1<<n):
            lst.append((get(S),get(T)))
            cnt=1

            with open('in.txt','w') as f:
                print(cnt,file=f)
                for x,y in lst:
                    print(n,file=f)
                    print(x,file=f)
                    print(y,file=f)

            print(f'testing {lst[0][0]} {lst[0][1]}')

            os.system('./d < in.txt > out1.txt')
            os.system('./dd < in.txt > out2.txt')

            l1=open('out1.txt').readlines()
            l2=open('out2.txt').readlines()

            if(l1!=l2):
                exit(0)

            lst=[]