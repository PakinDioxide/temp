#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 998244353;

ll poww(int x, int y) {
    if (y==0) return 1;
    ll k = poww(x, y/2) % mod;
    if (y % 2 == 0) return (k*k)%mod;
    else return (((k*k)%mod)*x)%mod;
}

ll inv(ll a) {
    return poww(a, mod-2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    pair <ll, ll> a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    for (int i = 0; i < n; i++) cin >> b[i].first, b[i].second = i;
    sort(a, a+n);
    sort(b, b+n);
    ll ida[n+5], idb[n+5];
    ll prd = 1;
    for (int i = 0; i < n; i++) ida[a[i].second+1] = i, idb[b[i].second+1] = i, prd = (prd * min(a[i].first, b[i].first)) % mod;
    cout << prd << ' ';
    while (q--) {
        ll o, x;
        cin >> o >> x;
        if (o == 1) {
            x = ida[x];
            int ox = x, ok = 0;
            // cout << "HA" << a[x].first << '\n';
            ll zz = min(a[x].first, b[x].first), yy = min(a[x].first, b[x].first);
            a[x].first++;
            // while (x < n-1 && a[x+1].first < a[ox].first) x++;
            x = lower_bound(a+ox+1, a+n, make_pair(a[ox].first, 0LL)) - a - 1;
            if (x < n && a[x].first < a[ox].first) {
                yy = min(a[x].first, b[x].first);
                ida[a[x].second+1] = ox;
                ida[a[ox].second+1] = x;
                swap(a[ox], a[x]);
                ok = 1;
            }
            if (ok) {
                prd = (prd*inv(zz))%mod;
                prd = (prd*inv(yy))%mod;
                prd = (prd*min(a[ox].first, b[ox].first))%mod;
                prd = (prd*min(a[x].first, b[x].first))%mod;
            } else {
                prd = (prd*inv(zz))%mod;
                prd = (prd*min(a[x].first, b[x].first))%mod;
            }
        } else {
            x = idb[x];
            int ox = x, ok = 0;
            // cout << "HA" << b[x].first << '\n';
            ll zz = min(a[x].first, b[x].first), yy = min(a[x].first, b[x].first);
            b[x].first++;
            x = lower_bound(b+ox+1, b+n, make_pair(b[ox].first, 0LL)) - b - 1;
            if (x < n && b[x].first < b[ox].first) {
                yy = min(a[x].first, b[x].first);
                idb[b[x].second+1] = ox;
                idb[b[ox].second+1] = x;
                swap(b[ox], b[x]);
                ok = 1;
            }
            if (ok) {
                prd = (prd*inv(zz))%mod;
                prd = (prd*inv(yy))%mod;
                prd = (prd*min(a[ox].first, b[ox].first))%mod;
                prd = (prd*min(a[x].first, b[x].first))%mod;
            } else {
                prd = (prd*inv(zz))%mod;
                prd = (prd*min(a[x].first, b[x].first))%mod;
            }
        }
        cout << prd << ' ';
        // cout << '\n';
        // for (int i = 0; i < n; i++) cout << a[i].first << ' ';
        // cout << '\n';
        // for (int i = 0; i < n; i++) cout << b[i].first << ' ';
        // cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}