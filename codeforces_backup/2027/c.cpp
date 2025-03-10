#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    pair <int, int> a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].first += i - 1, a[i].second = i - 1;
    a[0].first = a[0].second = -1;
    sort(a, a+n+1);
    map <int, int> vis;
    vis[n] = 1;
    int mx = n;
    for (int i = 1; i <= n; i++) {
        if (vis[a[i].first]) vis[a[i].first + a[i].second] = 1;
        if (vis[a[i].first]) mx = max(a[i].first + a[i].second, mx);
    }
    cout << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}