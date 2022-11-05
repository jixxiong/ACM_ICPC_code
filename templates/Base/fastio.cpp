#include <bits/stdc++.h>
using namespace std;

namespace Input {
    constexpr size_t BUF_SZ = 1 << 15;
    char buf[1 << 15];
    size_t pos, len;
    char nc() {
        if (pos == len) pos = 0, len = (size_t)fread(buf, 1, BUF_SZ, stdin);
        if (!len) return EOF;
        return buf[pos++];
    }
    template<typename T=int32_t> T read() {
        T x = 0; char ch; T flg = 1;
        while (!isdigit(ch = nc())) if (ch == '-') flg = -flg;
        while ( isdigit(ch)) x = x * 10 + (ch ^ '0'), ch = nc();
        return x * flg;
    }
}
using Input::read;

namespace Output {
    constexpr size_t BUF_SZ = 1 << 15;
    char buf[BUF_SZ];
    size_t pos;
    void flush() { fwrite(buf, 1, pos, stdout); pos = 0; }
    void putch(char c) {
        if (pos == BUF_SZ) flush();
        buf[pos++] = c;
    }
    void putstr(char const* str) { for(; *str; str++) putch(*str); }
    template<typename T> void print(T x) {
        static char num_buf[32];
        if (x < 0)  putch('-'), x = -x;
        size_t len = 0;
        for (; x >= 10; x /= 10) num_buf[len++] = (x % 10) ^ '0';
        putch(x ^ '0');
        while (len) putch(num_buf[--len]);
    }
    template<typename T> void println(T x) { print(x); putch('\n'); }
    __attribute((destructor)) void exit() { flush(); }
}
using Output::putch, Output::print, Output::println, Output::putstr;

int main() {
    int M = read();
    int N = 10;
    print(M);
    println(M + N);
    putstr("YES");
    putch('\n');
}
