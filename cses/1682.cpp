/*
    author  : PakinDioxide
    created : 22/03/2025 12:08
    task    : 1682
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[100005];
int vis[100005], lo[100005], id[100005], on[100005], sssc[100005], idx = 0, cnt = 0;
stack <int> st;

void dfs(int u) {
    lo[u] = id[u] = ++idx;
    vis[u] = 1;
    on[u] = 1;
    st.emplace(u);
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
        if (on[v]) lo[u] = min(lo[u], lo[v]);
    }
    if (lo[u] == id[u]) {
        cnt++;
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            sssc[v] = cnt;
            on[v] = 0;
            if (u == v) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    if (cnt == 1) {cout << "YES\n"; return 0;}
    cout << "NO\n";
    int idx1 = 0, idx2 = 0;
    for (int i = 1; i <= n; i++) {
        if (sssc[i] == 1) idx1 = i;
        if (sssc[i] == 2) idx2 = i;
    }
    cout << idx1 << ' ' << idx2 << '\n';
}