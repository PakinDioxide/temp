#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    ll a[n], vis[n], ans = n;
    for (int i = 0; i < n; i++) cin >> a[i], vis[i] = 0;
    sort(a, a+n);
    vector <pair <ll, pair <int, int>>> v;
    while (q--) {
        ll k;
        int l, r;
        cin >> l >> r >> k;
        v.push_back({-k, {l, r}});
    }
    sort(v.begin(), v.end());
    for (auto t : v) {
        ll k = -t.first, cnt = 0;
        int l = t.second.first, r = t.second.second;
        int idx = lower_bound(a, a+n, l) - a;
        vector <pair <int, int>> vv;
        for (int i = idx; i < n && a[i] <= r; i++) {
            if (vis[i]) cnt++;
            else 
        }
        ans -= max(0LL, k-cnt);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
