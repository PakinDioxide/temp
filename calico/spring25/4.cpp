/*
    author  : PakinDioxide
    created : 27/04/2025 06:31
    task    : 4
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m], ans = 0;
    vector <tuple <int, int, int>> v;
    v.emplace_back(0, 0, 0);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j], v.emplace_back(a[i][j], i, j);
    sort(v.begin(), v.end());
    for (int i = 0; i < n*m; i++) {
        int k, x, y, X, Y;
        tie(k, x, y) = v[i];
        tie(k, X, Y) = v[i+1];
        ans += min((X-x+n+n)%n, (x-X+n+n)%n) + min((Y-y+m+m)%m, (y-Y+m+m)%m);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}