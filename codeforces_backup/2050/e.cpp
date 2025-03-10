#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

string a, b, c;

map <pair <int, int>, int> vis, dp;

int r(int x, int y) {
    if (x == a.size() && y == b.size()) return 0;
    if (vis[{x, y}]) return dp[{x, y}];
    vis[{x, y}] = 1;
    int k = INT_MAX;
    if (x < a.size()) k = min(k, r(x+1, y) + (c[x+y] != a[x]));
    if (y < b.size()) k = min(k, r(x, y+1) + (c[x+y] != b[y]));
    return dp[{x, y}] = k;
}

void solve() {
    cin >> a >> b >> c;
    vis.clear(), dp.clear();
    cout << r(0, 0) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}