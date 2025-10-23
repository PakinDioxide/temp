/*
    author  : 
    created : 14/06/2025 22:43
    task    : 1546B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int dp[m][26]; memset(dp, 0, sizeof(dp));
    string s[2*n-1];
    for (auto &e : s) {
        cin >> e;
        for (int i = 0; i < m; i++) dp[i][e[i]-'a']++;
    }
    for (auto &e : s) {
        int ok = 1;
        for (int i = 0; i < m; i++) if (dp[i][e[i]-'a'] % 2 == 0) ok = 0;
        if (ok) {cout << e << endl; return;}
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}