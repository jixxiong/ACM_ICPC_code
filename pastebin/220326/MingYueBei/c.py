def main():
    print('223092870')

def cal():
    n=1000000000
    pm=[2,3,5,7,11,13,17,19,23,29,31,37,41,43]
    mul=1
    for i in range(len(pm)):
        if mul*pm[i]>n:
            print(mul)
            break
        else:
            mul*=pm[i]
    # 223092870

if __name__=='__main__':
    main()