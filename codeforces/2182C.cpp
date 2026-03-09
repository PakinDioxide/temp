#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n], b[n], c[n];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    for (auto &e : c) cin >> e;
    // a is fixed count a, b, count b, c
    ll A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int j = 0; j < n; j++) if (a[j] >= b[(i+j)%n]) { ok = 0; break; }
        A += ok;
    }
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int j = 0; j < n; j++) if (b[j] >= c[(i+j)%n]) { ok = 0; break; }
        B += ok;
    }
    cout << A*B*n << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

