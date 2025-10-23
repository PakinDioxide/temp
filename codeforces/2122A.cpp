/*
    author  : 
    created : 19/07/2025 21:35
    task    : 2122A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    if ((x >= 3 || y >= 3) && x != 1 && y != 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}