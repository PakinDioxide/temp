/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    int a[n+1]; a[0] = 0, a[1] = 1, a[2] = 2;
    for (int i = 3; i <= n; i++) a[i] = a[i-1] + a[i-2]; 
    while (q--) {
        int v[3];
        for (auto &e : v) cin >> e;
        sort(v, v+3);
        cout << (v[2] >= a[n]+a[n-1] && v[1] >= a[n] && v[0] >= a[n]);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

