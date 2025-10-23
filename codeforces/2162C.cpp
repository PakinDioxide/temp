#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll a, b; cin >> a >> b;
    vector <ll> v;
    for (int i = 0; (1 << i) <= a; i++) if (!(a & (1 << i))) v.emplace_back(1 << i), a |= (1 << i);
    ll k = a^b;
    if (k > a) cout << -1 << '\n';
    else {
        cout << v.size() + 1 << '\n';
        for (auto &e : v) cout << e << ' '; cout << k << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    void solve();
}