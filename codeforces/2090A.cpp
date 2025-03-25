/*
    author  : PakinDioxide
    created : 23/03/2025 12:32
    task    : 2090A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x, y, a;
    cin >> x >> y >> a;
    a %= (x+y);
    if (x > a) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}