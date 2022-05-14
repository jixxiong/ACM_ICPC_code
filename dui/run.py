import os
import random
import filecmp
import sys


def gen_data():
    with open('in.txt', 'w') as f:
        n = random.randint(1, 100)
        print(f'1\n{n}', file=f)
        for i in range(2):
            for j in range(n):
                print('.' if random.randint(0, 1)
                      == 0 else '*', end='', file=f)
            print('', file=f)


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
