#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n][n], cnt[n*n+5];
    memset(cnt, 0, sizeof(cnt));
    for (auto &E : a) for (auto &e : E) cin >> e, cnt[e]++;
    int mx = 0;
    for (auto &e : cnt) mx = max(mx, e);
    if (mx > n*n-n) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

