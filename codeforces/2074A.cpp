/*
    author  : PakinDioxide
    created : 11/03/2025 21:35
    task    : 2074A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if (l == d && l == r && l == u) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}