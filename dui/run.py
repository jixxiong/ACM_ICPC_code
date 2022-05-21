import os
import random
import filecmp
import sys


def gen_data(n=10000,m=1000000000):
    with open('in.txt', 'w') as f:
        print(f'1\n{random.randint(0,n)} {random.randint(0,n)}\n{random.randint(1,m)} {random.randint(1,m)} {random.randint(1,m)}\n',file=f)


def run_case():
    os.system("./sol < in.txt > sol_out.txt")
    os.system("./std < in.txt > std_out.txt")
    if not filecmp.cmp('sol_out.txt', 'std_out.txt'):
        print('rejected')
        sys.exit(0)
    else:
        print('accepted')


def main():
    random.seed(4933)
    os.system("g++ -o sol sol.cpp -O2 -std=c++17")
    os.system("g++ -o std std.cpp -O2 -std=c++17")
    cnt = 1
    while True:
        print(f'test {cnt} ', end='')
        cnt += 1
        gen_data()
        run_case()


if __name__ == '__main__':
    main()
