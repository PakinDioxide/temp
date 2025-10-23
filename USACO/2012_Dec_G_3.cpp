/*
    author  : PakinDioxide
    created : 16/07/2025 21:54
    task    : 2012_Dec_G_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5, mxL = 20;

int n, dep[mxN], up[mxL][mxN], ans[mxN];
ll dp[mxL][mxN], L;
vector <int> adj[mxN];

void dfs(int u) {
    int l = 0, r = n+1, idx = u;
    while (l <= r) {
        int x = l + (r-l)/2, k = u;
        ll s = 0;
        for (int c = 0; c < mxL; c++) if (x & (1 << c)) s += dp[c][k], k = up[c][k];
        if (s <= L) idx = k, l = x+1;
        else r = x-1;
    }
    ans[u]++, ans[up[0][idx]]--;
    for (auto v : adj[u]) dfs(v);
}

void dfs2(int u) { for (auto v : adj[u]) dfs2(v), ans[u] += ans[v]; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("runaway.in", "r", stdin);
    freopen("runaway.out", "w", stdout);
    cin >> n >> L;
    for (int i = 2; i <= n; i++) { int p; ll w; cin >> p >> w; adj[p].emplace_back(i); up[0][i] = p; dp[0][i] = w;}
    for (int c = 1; c < mxL; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]], dp[c][i] = dp[c-1][i] + dp[c-1][up[c-1][i]];
    dfs(1), dfs2(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}