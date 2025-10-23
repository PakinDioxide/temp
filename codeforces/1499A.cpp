/*
    author  : 
    created : 30/06/2025 22:30
    task    : 1499A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, x, y, p, q; cin >> n >> x >> y >> p >> q;
    if (min(x, y) + abs(x-y)/2 >= p && min(n-x, n-y) + abs(x-y)/2 >= q) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}