import os
import filecmp

os.system('g++ ./k.cpp -o ./k -O2 -Wall -std=c++17')
os.system('g++ ./kk.cpp -o ./kk -O2 -Wall -std=c++17')

for n in range(1,1000000):
    print(f'testing {n}',end=' ')
    with open('in.txt','w') as f:
        print(n,file=f)
    os.system('./k < in.txt > out1.txt')
    os.system('./kk < in.txt > out2.txt')
    with open('out1.txt','r') as f:
        print(f.readline().strip(),end=' ')
    with open('out2.txt','r') as f:
        print(f.readline().strip(),end=' ')
    if filecmp.cmp('out1.txt','out2.txt'):
        print('ACCEPTED')
    else:
        print('DIFFERENT')
        exit(0)