#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    priority_queue <tuple <ll, ll, ll, ll>> Q;
    ll dis[n+1][m+1], mk[k+1], mx = k;
    pair <ll, ll> v[k+1];
    memset(dis, 0, sizeof(dis));
    memset(mk, 0, sizeof(mk));
    for (ll i = 1; i <= k; i++) {
        ll x, y;
        cin >> x >> y;
        x++, y++;
        Q.emplace(-i, -i, x, y);
        v[i] = make_pair(x, y);
    }
    while (!Q.empty()) {
        auto [w, kk, x, y] = Q.top();
        Q.pop();
        w=-w;
        kk=-kk;
        if (x < 1 || y < 1 || x > n || y > m) continue;
        if (dis[x][y] <= kk && dis[x][y] && kk) mk[kk] = 1;
        if (dis[x][y]) continue;
        dis[x][y] = w;
        Q.emplace(-(w+1), 0, x+1, y);
        Q.emplace(-(w+1), 0, x, y+1);
        Q.emplace(-(w+1), 0, x-1, y);
        Q.emplace(-(w+1), 0, x, y-1);
        mx = max(mx, w);
    }
    ll p[mx+1], cnt[mx+1];
    memset(p, 0, sizeof(p));
    memset(cnt, 0, sizeof(cnt));
    // for (ll i = 1; i <= n; i++) {for (ll j = 1; j <= m; j++) cout << dis[i][j] << ' '; cout << '\n';}
    for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) p[dis[i][j]]++;
    for (ll i = 1; i <= mx; i++) cnt[i] += cnt[i-1] + mk[i] + p[i] + p[i-1], p[i] += p[i-1];
    while (q--) {
        ll d;
        cin >> d;
        if (d > mx) cout << cnt[mx] + (d - mx)*m*n << '\n';
        else cout << cnt[d] << '\n';
    }
}