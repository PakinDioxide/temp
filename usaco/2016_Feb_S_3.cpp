/*
    author  : PakinDioxide
    created : 02/05/2025 11:00
    task    : 2016_Feb_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    ll x, y, k, M;
    cin >> x >> y >> k >> M;
    ll dis[x+1][y+1], mn = LLONG_MAX;
    for (int i = 0; i <= x; i++) for (int j = 0; j <= y; j++) dis[i][j] = LLONG_MAX;
    queue <tuple <ll, ll, ll>> q;
    q.emplace(0, 0, 0);
    dis[0][0] = 0;
    while (!q.empty()) {
        auto [w, n, m] =  q.front(); q.pop();
        if (dis[n][m] != w) continue;
        mn = min(mn, abs(M-n-m));
        if (w == k) continue;
        if (dis[0][m] > w+1) q.emplace(dis[0][m] = w+1, 0, m);
        if (dis[n][0] > w+1) q.emplace(dis[n][0] = w+1, n, 0);
        if (dis[x][m] > w+1) q.emplace(dis[x][m] = w+1, x, m);
        if (dis[n][y] > w+1) q.emplace(dis[n][y] = w+1, n, y);
        if (dis[min(n+m, x)][max(0ll, n+m-x)] > w+1) q.emplace(dis[min(n+m, x)][max(0ll, n+m-x)] = w+1, min(n+m, x), max(0ll, n+m-x));
        if (dis[max(0ll, n+m-y)][min(n+m, y)] > w+1) q.emplace(dis[max(0ll, n+m-y)][min(n+m, y)] = w+1, max(0ll, n+m-y), min(n+m, y));
    }
    cout << mn << '\n';
}