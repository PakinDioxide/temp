/*
    author  : PakinDioxide
    created : 22/03/2025 15:34
    task    : 2017_Opn_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int n;
    cin >> n;
    string a[n];
    for (auto &e : a) cin >> e;
    int vis[n][n];
    vector <tuple <int, int, int, int>> v;
    for (int sx = 0; sx < n; sx++) for (int sy = 0; sy < n; sy++) for (int ex = sx; ex < n; ex++) for (int ey = sy; ey < n; ey++) {
        memset(vis, 0, sizeof(vis));
        vector <char> k;
        set <char> k2;
        for (int i = sx; i <= ex; i++) for (int j = sy; j <= ey; j++) {
            if (vis[i][j]) continue;
            k.push_back(a[i][j]);
            k2.insert(a[i][j]);
            queue <tuple <int, int>> q;
            q.emplace(i, j);
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (vis[x][y]) continue;
                vis[x][y] = 1;
                for (auto [dx, dy] : d) {
                    int nx = x+dx, ny = y+dy;
                    if (nx < sx || nx > ex || ny < sy || ny > ey || a[nx][ny] != a[i][j]) continue;
                    q.emplace(nx, ny);
                }
            }
        }
        if (k2.size() != 2) continue;
        int cnt1 = 0, cnt2 = 0;
        for (auto &e : k) {if (e == k[0]) cnt1++; else cnt2++;}
        if ((cnt1 == 1 && cnt2 >= 2) || (cnt1 >= 2 && cnt2 == 1)) v.emplace_back(sx, sy, ex, ey);
        
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        auto [sx, sy, ex, ey] = v[i];
        int ok = 1;
        for (int j = 0; j < v.size(); j++) {
            auto [ssx, ssy, eex, eey] = v[j];
            if (i == j) continue;
            if (ssx <= sx && ex <= eex && ssy <= sy && ey <= eey) {ok = 0; break;}
        }
        if (ok) cnt++;
    }
    cout << cnt << '\n';
}