/*
    author  : PakinDioxide
    created : 27/04/2025 13:30
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll a[mxN];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) { ll x, y; cin >> x >> y; a[i] = x*y; }
    int l = 1, r = 1;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        int L = l, R = r;
        if (a[i] >= a[i-1]) R = l+1;
        if (a[i] <= a[i-1]) L = r+1;
        l = L, r = R;
    }
    cout << max(l, r) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}