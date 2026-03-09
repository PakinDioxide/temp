#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    set <int> s;
    for (auto &e : a) s.emplace(e);
    int r = -1;
    while (1) {
        int x = s.size();
        if (x == r) { cout << x << '\n'; return; }
        r = x;
        s.emplace(x);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}