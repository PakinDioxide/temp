/*
    author  : 
    created : 23/06/2025 21:35
    task    : 2112A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, x, y; cin >> a >> x >> y;
    for (int i = 1; i <= 100; i++) if (abs(a-x) > abs(i-x) && abs(a-y) > abs(i-y)) { cout << "YES\n"; return; }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}