#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    // slope trick?
    ll shf = 0, mm = a[0];
    vector <pair <ll, ll>> v;
    ll L = a[0], ans = a[0];
    v.emplace_back(a[0], a[0]);
    for (int i = 1; i < n; i++) {
        ll x = a[i], y = -b[i];
        ans += x;
        shf += b[i];
        L = max(L-shf, x-shf);
        v.emplace_back(x-shf, x);
    }
    sort(v.begin(), v.end());
    // for (auto &[x, y] : v) cout << x << ' ' << y << '\n';
    ll c = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first > L) break;
        // cout << (v[i].first - v[i-1].first) * c << '\n';
        ans += (v[i].first - v[i-1].first) * c;
        c++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

