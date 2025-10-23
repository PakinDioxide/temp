/*
    author  : 
    created : 17/06/2025 21:37
    task    : 2121B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int vis[26]; memset(vis, 0, sizeof(vis));
    string s; cin >> s;
    for (auto &e : s) vis[e-'a']++;
    for (int i = 1; i < n-1; i++) if (vis[s[i]-'a'] >= 2) return (void) (cout << "Yes\n");
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}