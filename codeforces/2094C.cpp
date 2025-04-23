/*
    author  : PakinDioxide
    created : 13/04/2025 22:38
    task    : 2094C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n][n];
    for (auto &E : a) for (auto &e : E) cin >> e;
    int ans[2*n];
    map <int, int> mp;
    for (int i = 0; i < n; i++) ans[i+1] = a[0][i];
    for (int i = 0; i < n; i++) ans[i+n] = a[n-1][i];
    for (int i = 1; i < 2*n; i++) mp[ans[i]] = 1;
    for (int i = 1; i <= 2*n; i++) if (!mp[i]) ans[0] = i;
    for (int i = 0; i < 2*n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}