#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector <pair <ll, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (m == 0) {
        ll s = 0;
        for (int i = 1; i < n; i++) s += a[i].first;
        if (s < a[0].first) { cout << -1 << '\n'; return; }
        s = a[0].first;
        int sz = n;
        vector <pair <int, int>> ans;
        while (sz > 2 && s - a[sz-1].first > 0) s -= a[sz-1].first, ans.emplace_back(a[sz-1].second, a[0].second), sz--, a.pop_back();
        while (sz > 2) ans.emplace_back(a[sz-1].second, a[sz-2].second), sz--, a.pop_back(), a.pop_back();
        ans.emplace_back(a[0].second, a[1].second);
        cout << ans.size() << '\n';
        for (auto &[x, y] : ans) cout << x+1 << ' ' << y+1 << '\n';
        return;
    }
    int sz = n;
    vector <pair <int, int>> ans;
    for (int i = 0; (n-i-1)/2 >= m; i++) ans.emplace_back(a[sz-1].second, a[sz-2].second), a.pop_back(), sz--;
    if (sz/2 < m) { cout << -1 << '\n'; return; }
    int rc = 0;
    while (sz >= 2) ans.emplace_back(a[sz-2].second, a[sz-1].second), rc = a[sz-2].second, sz -= 2, a.pop_back(), a.pop_back();
    if (sz) ans.emplace_back(a[0].second, rc);
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) cout << x+1 << ' ' << y+1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*
at least one will die

if m > n/2 -> no
else should be yes (?)

if n/2
2*x kill 2*x-1


*/
