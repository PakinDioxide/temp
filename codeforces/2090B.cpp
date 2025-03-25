/*
    author  : PakinDioxide
    created : 23/03/2025 12:32
    task    : 2090B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ok[n][m];
    memset(ok, 0, sizeof(ok));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m && a[i][j] == '1'; j++) ok[i][j] = 1;
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n && a[i][j] == '1'; i++) ok[i][j] = 1;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == '1') ans = min(ans, ok[i][j]);
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}