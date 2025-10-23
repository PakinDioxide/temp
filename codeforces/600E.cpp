/*
    author  : 
    created : 19/07/2025 16:16
    task    : 600E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n;
ll ans[mxN], c[mxN];
vector <int> adj[mxN];
map <ll, ll> cnt[mxN], sum[mxN];

void dfs(int u, int p) {
    cnt[u][c[u]] = 1;
    sum[u][1] = c[u];
    for (auto v : adj[u]) if (v != p) {
        dfs(v, u);
        if (cnt[u].size() < cnt[v].size()) {
            swap(cnt[u], cnt[v]);
            swap(sum[u], sum[v]);
        }
        for (auto &[col, cc] : cnt[v]) {
            if (cnt[u][col] > 0) sum[u][cnt[u][col]] -= col;
            cnt[u][col] += cc;
            sum[u][cnt[u][col]] += col;
        }
    }
    ans[u] = (*prev(sum[u].end())).second;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v), adj[v].emplace_back(u); }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
}