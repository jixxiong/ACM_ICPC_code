def cal(n,m):
    p=998244353
    dp=[[0 for i in range(n+m+10)]for j in range(n+m+10)]
    dp[0][0]=1
    for i in range(1,n+1):
        for j in range(0,i+1):
            for k in range(max(0,j-1),min(i-1,j+m-1)+1):
                dp[i][j]+=dp[i-1][k]
                dp[i][j]%=p
    print(dp[n][0])


def main():
    print('313168820')

if __name__=='__main__':
    # cal(3,2)
    # cal(520,20)
    main()