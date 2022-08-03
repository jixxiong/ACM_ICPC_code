#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 2500;
const double pi = acos(-1.0);
int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int cnt, n;
struct data {
    double l, r;
    friend bool operator < (data a, data b) {return a.l < b.l;}
}opt[N];
struct C {
    double x, y, r;
    C(double a = 0, double b = 0, double c = 0) : x(a), y(b), r(c) {}
    C operator - (C a) {return C(x - a.x, y - a.y, 0);}
    double operator ^ (C a) {return x * a.x + y * a.y;}
}p[N];
double sqr(double x) {return x * x;}
double sqr(C a) {return a ^ a;}
double angle(C p) {return atan2(p.y, p.x);}
double angle(double a, double b, double c) {return acos((a * a + b * b - c * c) / (2 * a * b));}
void add(double a, double b) {opt[++cnt].l = a; opt[cnt].r = b;}
void Solve(C u, C v, double dis) {
    double t1 = angle(u - v), t2 = angle(u.r, dis, v.r);
    double l = t1 - t2, r = t1 + t2;
    if(l < 0) l += 2 * pi;
    if(r < 0) r += 2 * pi;
    if(l > r) {add(0, r); add(l, 2 * pi);}
    else add(l, r);
}
double calc() {
    sort(opt + 1, opt + cnt + 1); double l = -10, r = -10, ret = 0;
    for(int i = 1;i <= cnt; ++i) 
    if(opt[i].l > r) {ret += r - l; l = opt[i].l; r = opt[i].r;}
    else r = max(r, opt[i].r);
    ret += r - l; return 2 * pi - ret;
}

int main() {
    scanf("%d", &n);
    for(int i = n; i; --i) scanf("%lf%lf%lf", &p[i].r, &p[i].x, &p[i].y);
    double ans = 0;
    for(int i = 1, j;i <= n; ++i) {
        cnt = 0;
        for(j = 1;j < i; ++j) {
            double dis = sqrt(sqr(p[j] - p[i]));
            if(p[j].r - p[i].r > dis) break;
            if(p[j].r + p[i].r > dis && fabs(p[j].r - p[i].r) < dis) Solve(p[i], p[j], dis);
        }
        if(j == i) ans += p[i].r * calc();
    }
    printf("%.3lf\n", ans);
    return 0;
}