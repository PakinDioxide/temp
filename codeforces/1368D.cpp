#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; ll c;
    cin >> n >> c;
    ll a[n+1], b[n+1]; for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    vector <pair <ll, int>> v;
    for (int i = 1; i <= n; i++) v.emplace_back(min(a[i] + i, n - i + 1 + a[i]), i);
    sort(v.begin(), v.end());
    int idx[n+1];
    for (int i = 0; i < n; i++) idx[v[i].second] = i;
    for (int i = 1; i < n; i++) v[i].first += v[i-1].first;
    for (int i = 0; i < n; i++) a[i] = v[i].first;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        if (i + b[i] > c) continue;
        ll k = c - i - b[i];
        // cout << i << ' ';
        if (idx[i] > 0) mx = max(mx, (int) (upper_bound(a, a+idx[i]-1, k) - a));//, cout << "R " << (int) (upper_bound(a, a+idx[i]-1, k) - a) << ' ';
        if (idx[i] < n && k + a[idx[i]] - (idx[i] == 0 ? 0 : a[idx[i]-1]) >= a[idx[i]]) mx = max(mx, (int) (upper_bound(a+idx[i], a+n, k + a[idx[i]] - (idx[i] == 0 ? 0 : a[idx[i]-1])) - a) - 1);//, cout << "L " << ((int) ((upper_bound(a+idx[i], a+n, k + a[idx[i]]) - a) - 1)) << ' ';
        // cout << '\n';
    }
    cout << mx+1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
