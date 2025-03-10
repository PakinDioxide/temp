#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int rd = n - r;
    int ech = m - 1 + 1 + m - 1;
    cout << rd * ech + (m - c) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}