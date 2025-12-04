#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    // nogud
    int n; ll q; cin >> n >> q;
    ll a[n], Q = 0; for (auto &e : a) cin >> e;
    reverse(a, a+n);
    vector <int> v;
    ll cnt = 0;
    for (auto &e : a) {
        if (e <= Q) cnt++, v.emplace_back(1);
        else if (e > Q && Q < q) cnt++, Q++, v.emplace_back(1);
        else v.emplace_back(0);
    }
    while (!v.empty()) cout << v.back(), v.pop_back();
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}