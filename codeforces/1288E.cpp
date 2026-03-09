#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    vector <int> v(m); for (auto &e : v) cin >> e;
    int mn[n+1], mx[n+1];
    for (int i = 1; i <= n; i++) mn[i] = mx[i] = i;
    for (auto &e : v) mn[e] = 1;
    reverse(v.begin(), v.end());
    for (int i = 1; i <= n; i++) v.emplace_back(i);
    m = v.size();
    vector <int> fen(m+1);
    auto upd = [&] (int idx, int x) {
        if (idx == 0) return;
        for (int i = idx; i <= m; i += i & -i) fen[i] += x;
    };
    auto qr = [&] (int idx) {
        int x = 0;
        for (int i = idx; i > 0; i -= i & -i) x += fen[i];
        return x;
    };
    int rc[n+1]; memset(rc, 0, sizeof(rc));
    for (int i = 1; i <= m; i++) {
        int e = v[i-1];
        mx[e] = max(mx[e], 1 + qr(i) - qr(rc[e]));
        upd(rc[e], -1);
        rc[e] = i;
        upd(rc[e], 1);
    }
    for (int i = 1; i <= n; i++) cout << mn[i] << ' ' << mx[i] << '\n';
}

