/*
    author  : PakinDioxide
    created : 16/03/2025 01:04
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n], ok = 0;
    for (auto &e : a) cin >> e;
    for (int i = -1; i < n; i++) {
        ll l = -1, r = -1, k = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (!(a[i] <= l || a[i] >= r)) {k = 0; break;}
                continue;
            }
            if (l == -1) l = a[j], r = a[j];
            else if (a[j] <= l) l = a[j];
            else if (a[j] >= r) r = a[j];
            else {k = 0; break;}
        }
        ok = max(ok, k);
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}