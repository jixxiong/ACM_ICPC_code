
# dic = {'a': 32, 'b': 34}
#
# print(eval('a + b', dic))

mod = 998244353

def qpow(a, b):
    if b == 0: return 1
    ret = 1
    while b:
        if b & 1: ret = ret * a % mod
        a = a * a % mod
        b >>= 1
    return ret

for _ in range(int(input())):
    n = int(input())
    mp = [[] for i in range(26)]
    fm = qpow(1000000, mod - 2)
    for _ in range(n):
        s = input().strip().split()
        ch = s[0]
        k  = s[1]
        for i in range(int(k)):
            x, p = int(s[2 + 2 * i]) % mod, s[2 + 2 * i + 1]
            if p[0] == '1':
                mp[ord(ch) - ord('a')].append((x, 1))
            else:
                mp[ord(ch) - ord('a')].append((x, int(p[2:]) * fm % mod))
    experssion = input()

    exp = ""
    for ch in experssion:
        if ch not in ('*', '-', '+'):
            exp += '% mod'
        exp += ch

    exp = f'(({exp})%mod+mod)%mod'

    dic = {'mod': mod}
    ret = 0

    def dfs(i, prob):
        global ret
        if i >= 26:
            ret = (ret + eval(experssion, dic) * prob % mod) % mod
            return
        if len(mp[i]) == 0:
            dfs(i + 1, prob)
        for x, p in mp[i]:
            dic[chr(ord('a') + i)] = x
            dfs(i + 1, prob * p % mod)

    dfs(0, 1)

    print(ret)
