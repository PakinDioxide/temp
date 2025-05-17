// BRUTE FORCE
/*
    author  : PakinDioxide
    created : 02/05/2025 00:18
    task    : e
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e4+5;

int n, k, mod = 1e9+7;//, dp[2][mxN];
vector <int> adj[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, e; cin >> x;
        while (x--) cin >> e, adj[i].emplace_back(e);
    }
    // for (int i = 0; i < n; i++) dp[0][i] = 1;
    // int ans = 0;
    // for (int i = 1; i < k; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int x = 0;
    //         for (auto &e : adj[j]) x += dp[!(i&1)][e], x %= mod;
    //         dp[i&1][j] = x;
    //     }
    // }
    // for (int i = 0; i < n; i++) ans += dp[!(k&1)][i];
    // cout << ans << '\n';
}