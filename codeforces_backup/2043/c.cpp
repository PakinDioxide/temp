#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n+1], idx = n+1;
    set <ll> ans, ans2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1) idx = i;
    }
    ans.insert(0);
    ll k = 0, mn = 0, mx = 0;
    for (int i = 1; i < idx; i++) {
        k += a[i];
        mn = min(mn, k), mx = max(mx, k);
        ans.insert(k);
        if (*ans.begin() > k - mx) ans.insert(k-mx);
        if (*ans.rbegin() < k - mn) ans.insert(k-mn);
    }
    k = 0, mn = 0, mx = 0;
    for (int i = idx+1; i <= n; i++) {
        k += a[i];
        mn = min(mn, k), mx = max(mx, k);
        ans2.insert(k);
        if (*ans2.begin() > k - mx) ans2.insert(k-mx);
        if (*ans2.rbegin() < k - mn) ans2.insert(k-mn);
    }
    if (ans2.size() > ans.size()) swap(ans, ans2);
    for (ll i : ans2) ans.insert(i);
    if (idx <= n) ans.insert(a[idx]);

    set <ll> p, q;
    if (idx <= n) {
        p.insert(0), q.insert(0);
        ll k = 0;
        for (int i = idx-1; i > 0; i--) {
            k += a[i];
            p.insert(k);
        }
        k = 0;
        for (int i = idx+1; i <= n; i++) {
            k += a[i];
            q.insert(k);
        }
        for (ll i : p) for (ll j : q) ans.insert(i + j + a[idx]);
    }

    cout << ans.size() << '\n';
    for (ll i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}