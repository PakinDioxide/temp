#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[m], b[k], v[n+1];
    for (int i = 1; i <= n; i++) v[i] = 0;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i], v[b[i]] = 1;
    for (int i = 0; i < m; i++) {
        if (k < n-1) cout << 0;
        else if (k == n || !v[a[i]]) cout  << 1;
        else cout << 0;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}