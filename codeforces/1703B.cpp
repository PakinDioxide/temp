/*
    author  : 
    created : 30/06/2025 22:12
    task    : 1703B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int vis[26]; memset(vis, 0, sizeof(vis));
    string s; cin >> s;
    int cnt = n;
    for (auto &e : s) cnt += !vis[e-'A'], vis[e-'A'] = 1;
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}