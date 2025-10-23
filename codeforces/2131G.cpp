/*
    author  : 
    created : 10/08/2025 23:28
    task    : 2131G
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7, mxN = 40;

ll p[mxN], c[mxN], v[mxN], vp[mxN];

void solve() {
    int n; ll k; cin >> n >> k;
    ll a[n]; for (auto &e : a) cin >> e;
    sort(a, a+n);
    ll s = 1;
    for (auto &e : a) {
        if (k == 0) break;
        if (e >= mxN || k < v[e]) {
            while (k > 0) {
                k--; s *= e; s %= mod;
                if (k == 0) break;
                int l = 0;
                while (v[l] <= k) l++; l--;
                s *= c[l]; s %= mod;
                k -= v[l];
                e = l+1;
                cout << " L " << l << ' ' << k << '\n';
            }
            break;
        } else s *= c[e], s %= mod, k -= v[e];
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    p[0] = 1, c[0] = 1;
    for (int i = 1; i < mxN; i++) c[i] = (i * p[i-1]) % mod, p[i] = (p[i-1] * c[i]) % mod, v[i] = vp[i-1] + 1, vp[i] = vp[i-1] + v[i], cout << i << ' ' << c[i] << '\n';
    while (t--) solve();
}