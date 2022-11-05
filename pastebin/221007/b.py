from decimal import *

a, b, k = map(int, input().strip().split())

getcontext().prec = k
c = Decimal(a) / Decimal(b)
c = str(c)
while len(c) < k:
    c += '0'
print(c)
