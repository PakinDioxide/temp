/*
    author  : PakinDioxide
    created : 16/03/2025 18:42
    task    : D2_C
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    pair <ll, ll> v[n];
    for (auto &[x, e] : v) cin >> x >> e;
    sort(v, v+n);
    ll a[n];
    for (int i = 0; i < n; i++) a[i] = v[i].second; //, cerr << a[i] << ' ';
    // cerr << '\n';
    ll l = 1, r = 1e9, ans = LLONG_MIN;
    while (l <= r) {
        ll m = l + (r-l)/2, sum = 0;
        vector <ll> d;
        // cout << "M : " << m << '\n';
        for (int i = n-1; i >= 0; i--) {
            ll e = a[i];
            int idx = upper_bound(d.begin(), d.end(), e-m) - d.begin();
            if (idx == d.size()) d.push_back(e);
            else if (d[idx] > e) d[idx] = e;
            // for (int lll : d) cout << lll << ' ';
            // cout << '\n';
        }
        if (d.size() >= k) ans = m, l = m+1;
        else r = m-1;
    }
    cout << (ans == LLONG_MIN ? -1 : ans) << '\n';
}