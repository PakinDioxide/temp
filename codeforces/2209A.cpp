#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; ll c, k; cin >> n >> c >> k;
    ll a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    for (auto &e : a) {
        if (e <= c) {
            ll ee = min(c, e+k);
            k -= ee-e;
            c += ee;
        }
        else break;
    }
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

