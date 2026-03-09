#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    ll a[n][m];
    for (auto &E : a) for (auto &e : E) cin >> e;
    ll L = 0, R = 1e9, ans = 0;
    while (L <= R) {
        ll x = L + (R-L)/2;
        ll vis[(1 << 8)]; memset(vis, 0, sizeof(vis));
        ll K[n];
        vis[0] = 1;
        for (int i = 0; i < n; i++) {
            ll k = 0;
            for (int j = 0; j < m; j++) if (a[i][j] >= x) k |= (1 << j);
            K[i] = k;
            for (int j = k; j > 0; j = (j - 1) & k) vis[j] = i+1;
        }
        ll hv = 0;
        for (auto &e : K) hv = max(hv, vis[((1 << m) - 1) ^ e]);
        if (hv) ans = x, L = x+1;
        else R = x-1;
    }
    ll x = ans;
    ll vis[(1 << 8)]; memset(vis, 0, sizeof(vis));
    ll K[n];
    vis[0] = 1;
    for (int i = 0; i < n; i++) {
        ll k = 0;
        for (int j = 0; j < m; j++) if (a[i][j] >= x) k |= (1 << j);
        K[i] = k;
        for (int j = k; j > 0; j = (j - 1) & k) vis[j] = i+1;
    }
    for (int i = 0; i < n; i++) {
        int e = K[i];
        if (vis[((1 << m) - 1) ^ e]) { cout << i+1 << ' ' << vis[((1 << m) - 1) ^ e] << '\n'; return 0; }
    }
}

