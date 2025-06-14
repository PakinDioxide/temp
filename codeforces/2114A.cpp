/*
    author  : PakinDioxide
    created : 26/05/2025 21:35
    task    : 2114A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll s; cin >> s;
    int k = sqrt(s);
    if (k*k == s) cout << 0 << ' ' << k << '\n';
    else cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}