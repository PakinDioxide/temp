#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector <tuple <ll, ll, ll>> adj;
    for (ll i = 0, u, v, w; i < m; i++) cin >> u >> v >> w, adj.emplace_back(u, v, w), adj.emplace_back(v, u, w);
    ll dp[n][k+1], mx[n][k+1];
    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) dp[i][j] = mx[i][j] = INT_MAX;
    for (int j = 0; j < n; j++) {
        for (auto [u, v, w] : adj) {
            for (int i = 0; i <= k; i++) {
                if (dp[u])
            }
        }
    }
}