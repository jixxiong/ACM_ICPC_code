

f=[int(1e200) for i in range(10010)]

def fuk():
    f[1]=1
    file=open('out.txt','w')
    for i in range(2,10001):
        for j in range(i-1,0,-1):
            if pow(2,i-j)>1e100:
                break
            f[i]=min(f[i],f[j]*2+pow(2,i-j)-1)
        print(f'{i} {f[i]}',file=file) #374931278650296101567069263458900577819295745

def main():
    fuk()
    T=int(input())
    while T>0:
        T-=1
        n=int(input())
        print(f[n])

if __name__=="__main__":
    main()