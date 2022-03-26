def cal():
    pr=[]
    for i in range(3):
        for j in range(3):
            pr.append((i,j))
    cnt=0
    for x1,y1 in pr:
        for x2,y2 in pr:
            if x1==x2 and y1==y2:
                continue
            if (x1==x2 and abs(y1-y2)==2) or \
                (y1==y2 and abs(x1-x2)==2) or \
                (abs(y1-y2)==2 and abs(x1-x2)==2):
                continue
            for x3,y3 in pr:
                if (x1==x3 and y1==y3) or \
                    (x2==x3 and y2==y3):
                    continue
                if (x2==x3 and abs(y2-y3)==2) or \
                    (y2==y3 and abs(x2-x3)==2) or \
                    (abs(y2-y3)==2 and abs(x2-x3)==2):
                    continue
                for x4,y4 in pr:
                    if (x1==x4 and y1==y4) or \
                        (x2==x4 and y2==y4) or \
                        (x3==x4 and y3==y4):
                        continue
                    if (x3==x4 and abs(y3-y4)==2) or \
                        (y3==y4 and abs(x3-x4)==2) or \
                        (abs(y3-y4)==2 and abs(x3-x4)==2):
                        continue
                    t1=(y1-y2)*(x3-x1)-(x1-x2)*(y3-y1)
                    t2=(y1-y2)*(x4-x1)-(x1-x2)*(y4-y1)
                    if t1*t2>=0:
                        # print(f"({x1},{y1}),({x2},{y2}),({x3},{y3}),({x4},{y4})")
                        print(f"{x1} {y1} {x2} {y2} {x3} {y3} {x4} {y4}")
                        cnt+=1
    print(cnt//2)

            

def main():
    print('524')

if __name__=='__main__':
    # main()
    cal()

