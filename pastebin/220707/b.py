import sys 
from  random import randint

input = sys.stdin.readline
print = sys.stdout.write

def get1(x):
    n, m = map(int, input().split())
    s = '-' + input().strip()
    d = n // (m + 1)
    r = n % (m + 1)
    dp = [[10 ** (n+1) for i in range(n + 10)] for j in range(n + 10)]
    dp[0][0] = 0
    for i in range(d, n + 1):
        dp[i][0] = eval(s[1:i+1])
        for j in range(1, m + 1):
            for k in range(d, d + 5):
                if i>=k:
                    dp[i][j]=min(dp[i][j],dp[i-k][j-1]+eval(s[i-k+1 : i+1]))
                else:
                    break
    return dp[n][m]
 
def get2(x):
    n, m = map(int, input().split())
    s = '-' + input().strip()
    d = n // (m + 1)
    r = n % (m + 1)
    dp = [[10 ** (n+1) for i in range(r + 10)] for j in range(n + 10)]
    dp[0][0] = 0
    for i in range(d, n + 1):
        for j in range(0, r+1):
            dp[i][j]=min(dp[i][j],dp[i-d][j]+eval(s[i-d+1 : i+1]))
        if i>d:
            for j in range(1,r+1):
                dp[i][j]=min(dp[i][j],dp[i-(d+1)][j-1]+eval(s[i-d : i+1]))
    return dp[n][r]

if __name__=='__main__':
    n = 10
    m = randint(1, n - 1)
    while True:
        a = ''.join([chr(ord('0') +  randint(1, 9)) for i in range(n)])
        if get1(a) != get2(a):
            print(f'{a}\n')
            exit(0)
        