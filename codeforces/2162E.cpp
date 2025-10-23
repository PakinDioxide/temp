#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    ll a[n]; for (auto &e : a) cin >> e;
    ll c[n+1]; memset(c, 0, sizeof(c));
    for (auto &e : a) c[e]++;
    vector <int> v;
    for (int i = 1; i <= n; i++) if (c[i] == 0) v.emplace_back(i);
    if (v.size() >= 3) {
        for (int i = 0; i < k; i++) cout << v[i%3] << ' ';
        cout << '\n'; return;
    } else if (v.size() == 2) {
        for (int i = 1; i <= n; i++) if (c[i] != 0) { v.emplace_back(i); break; }
        for (int i = 0; i < k; i++) cout << v[i%3] << ' ';
        cout << '\n'; return;
    } else if (v.empty()) {
        for (int i = 0; i < k; i++) cout << a[i] << ' '; cout << '\n'; return;
    } else {
        for (int i = 1; i <= n; i++) if (c[i] != 0 && i != a[n-1]) { v.emplace_back(i); break; }
        for (int i = 1; i <= n; i++) if (c[i] != 0 && i != v.back()) { v.emplace_back(i); break; }
        for (int i = 0; i < k; i++) cout << v[i%3] << ' ';
        cout << '\n'; return;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    void solve();
}

/*
choose 3 and a b c a b c a b c ..

wtf
*/