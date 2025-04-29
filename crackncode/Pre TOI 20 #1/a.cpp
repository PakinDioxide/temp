/*
    author  : PakinDioxide
    created : 28/04/2025 18:57
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1005, mxM = 705;
int dp[mxM][mxN], n, m, k;

void solve() {
    int M; cin >> M;
    vector <int> adj[n+1];
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    vector <int> ok(n+1), lo(n+1), id(n+1), onst(n+1), G[n+1];
    stack <int> st;
    int idx = 0;
    function <void(int, int)> dfs = [&] (int u, int p) {
        id[u] = lo[u] = ++idx;
        onst[u] = 1;
        st.emplace(u);
        for (auto v : adj[u]) {
            if (!id[v]) dfs(v, u);
            lo[u] = min(lo[u], lo[v]);
        }
        if (id[u] == lo[u]) {
            while (!st.empty()) {
                if (onst[st.top()]) lo[st.top()] = lo[u], onst[st.top()] = 0, G[lo[u]].emplace_back(st.top());
                if (st.top() == u) {st.pop(); break;}
                st.pop();
            }
        }
    };
    for (int i = 1; i <= n; i++) if (!id[i]) dfs(i, i);
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
}