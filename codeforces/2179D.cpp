#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n; cin >> n;
    vector <ll> v;
    for (ll i = n; i >= 0; i--) {
        v.emplace_back((1LL << i) - 1);
        for (ll ii = 1; ii < (1 << (n-(i+1))); ii++) v.emplace_back((ii<<(i+1)) + (1LL << i) - 1);
    }
    for (auto &e : v) cout << e << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

