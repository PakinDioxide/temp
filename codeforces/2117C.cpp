/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    int vis[n+1]; for (auto &e : vis) e = INT_MAX;
    int cnt = 0, ans = 0, ct = n-1;
    int p[n];
    for (int i = 0; i < n; i++) {
        auto e = a[i];
        if (vis[e] == INT_MAX) vis[e] = i, p[i] = (i > 0 ? p[i-1] : 0) + 1;
        else p[i] = (i > 0 ? p[i-1] : 0);
    }
    // for (int i = 0; i < n; i++) cout << p[i] << ' ';
    // cout << '\n';
    for (auto &e : vis) e = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        if (vis[a[i]] > ct) cnt++;
        vis[a[i]] = i;
        // cout << i << ' ' << cnt << '\n';
        if (i == 0 || cnt >= p[ct]) {
            ans++;
            ct = i-1;
            cnt = 0;
        }
    }
    // cout << '\n';
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

