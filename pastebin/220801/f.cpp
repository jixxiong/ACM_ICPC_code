#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
using namespace std;
int r, c, k;
bool vis[505][505];
char mp[505][505];
int h[4] = { 0,0,-1,1 };
int l[4] = { 1,-1,0,0 };
void dfs(int x, int y) {
    int flag = 0;
    for (int i = 0;i < 4;++i) {
        int nx = x + h[i], ny = y + l[i];
        if (x + h[i] >= 1 && x + h[i] <= r && y + l[i] >= 1 && y + l[i] <= c) {
            if (mp[x + h[i]][y + l[i]] == 'X' && vis[nx][ny] == 0)
            {
                vis[x + h[i]][y + l[i]] = 1;
                if (k > 0) {
                    mp[x + h[i]][y + l[i]] = '.';
                    k--;
                    if (k == 0) {
                        for (int i = 1;i <= r;++i)
                            cout << mp[i] + 1 << '\n';
                        exit(0);
                    }
                }
                dfs(x + h[i], y + l[i]);
                vis[x][y] = 0;
            }
        }
    }
}
int main()
{
    cin >> r >> c >> k;
    int a, b, nu = 0;
    for (int i = 1;i <= r;++i)
        scanf("%s", mp[i] + 1);
    for (int i = 1;i <= r;++i)
        for (int j = 1;j <= c;++j) {
            if (mp[i][j] == '.') {
                mp[i][j] = 'X';
                nu++;
                a = i;
                b = j;
            }
        }

    k = nu - k;
    dfs(a, b);


    return 0;
}