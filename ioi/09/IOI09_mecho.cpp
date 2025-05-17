/*
    author  : PakinDioxide
    created : 29/03/2025 13:16
    task    : IOI09_mecho
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, s;
    cin >> n >> s;
    string a[n];
    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue <tuple <ll, int, int>> q;
    ll dis[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dis[i][j] = LLONG_MAX;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (a[i][j] == 'M') sx = i, sy = j;
        else if (a[i][j] == 'D') ex = i, ey = j;
        else if (a[i][j] == 'H') q.emplace(0, i, j), dis[i][j] = 0;
    }
    while (!q.empty()) {
        auto [w, x, y] = q.top();
        q.pop();
        w=-w;
        if (w != dis[x][y]) continue;
        for (auto [dx, dy] : d) {
            int nx = x+dx, ny = y+dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] == 'T' || a[nx][ny] == 'D') continue;
            if (dis[nx][ny] > w+1) q.emplace(-(dis[nx][ny] = w+1), nx, ny);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << (dis[i][j] == LLONG_MAX ? -1 : dis[i][j]) << ' ';
    //     cout << '\n';
    // }
    priority_queue <tuple <pair <ll, ll>, int, int>> Q;
    ll l = 0, r = n*n, ans = -1;
    while (l <= r) {
        ll k = l + (r-l)/2, ok = 0;
        Q.emplace(make_pair(-k, 0LL), sx, sy);
        pair <ll, ll> dis2[n][n];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dis2[i][j] = {LLONG_MAX, LLONG_MAX};
        dis2[sx][sy] = {k, 0};
        while (!Q.empty()) {
            auto [w, x, y] = Q.top();
            Q.pop();
            w.first = -w.first;
            w.second = -w.second;
            if (dis2[x][y] != w) continue;
            if (dis[x][y] <= w.first) continue;
            // cout << k << ' ' << dis[x][y] << ' ' << w << ' ' << x << ' ' << y << '\n';
            if (x == ex && y == ey) {
                ok = 1;
                break;
            }
            pair <ll, ll> nw = {w.first + (w.second + 1 == s), (w.second + 1) % s};
            pair <ll, ll> nnw = {-nw.first, -nw.second};
            for (auto [dx, dy] : d) {
                int nx = x+dx, ny = y+dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] == 'T') continue;
                if (dis2[nx][ny] > nw) {
                    dis2[nx][ny] = nw;
                    Q.emplace(nnw, nx, ny);
                }
            }
        }
        while (!q.empty()) q.pop();
        if (ok) l = k+1, ans = k;
        else r = k-1;
    }
    cout << ans << '\n';
}