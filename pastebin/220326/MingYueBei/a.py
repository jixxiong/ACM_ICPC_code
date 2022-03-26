def main():
    print('29127')

def cal():
    ret,p=0,65536
    for x in range(9,0,-1):
        for i in range(10000):
            ret=ret*10+x
            ret%=p
    print(ret)

if __name__=='__main__':
    cal()

