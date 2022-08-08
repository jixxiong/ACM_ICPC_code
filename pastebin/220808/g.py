import re
import sys

input = sys.stdin.readline
print = sys.stdout.write

charset1=''.join([chr(i) for i in range(ord('a'),ord('z')+1)])+'.'
charset2=''.join([chr(i) for i in range(ord('a'),ord('z')+1)])+'.*+'

candidate_pattern=[c1+c2 for c1 in charset1 for c2 in charset2]

# print(str(re.match('q*', 'ab'))+'1')

for _ in range(int(input())):
    s=input().strip()
    if len(s)==1:
        print("1 2\n")
    else:
        ans=0
        for candidate in candidate_pattern:
            ret = re.match(candidate, s)
            if (ret is not None) and (ret.span()==(0,len(s))):
                ans+=1
        print(f"2 {ans}\n")