#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int mx = 0, idx = -1;
    vector <pair <int, int>> v;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        v.emplace_back(l, r);
        if (r-l+1 > mx) mx = r-l+1, idx = i;
    }
    if (mx == n) {
        for (int i = 0; i < n; i++) cout << i << ' ';
        cout << '\n'; return;
    }
    int a[n+1]; for (int i = 1; i <= n; i++) a[i] = -1;
    if (v[idx].second < n) a[v[idx].first] = 1, a[v[idx].second+1] = 0;
    else a[v[idx].first-1] = 0, a[v[idx].second] = 1;
    int it = 2;
    for (int i = 1; i <= n; i++) if (a[i] == -1) a[i] = it++;
    for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    void solve();
}

/*
1 -> 0
2 -> 1 0
*/