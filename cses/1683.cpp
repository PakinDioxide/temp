#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100005];
stack <int> st;
int onst[100005], lo[100005], id[100005], cnt = 0, ans[100005], cntans = 0;

void dfs(int u) {
    id[u] = lo[u] = ++cnt;
    onst[u] = 1;
    st.emplace(u);
    for (int v : adj[u]) {
        if (!id[v]) dfs(v);
        if (onst[v]) lo[u] = min(lo[u], lo[v]);
    }
    if (lo[u] == id[u]) {
        cntans++;
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            lo[v] = lo[u];
            ans[v] = cntans;
            onst[v] = 0;
            if (u == v) break;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
    }
    for (int i = 1; i <= n; i++) if (!id[i]) dfs(i);
    printf("%d\n", cntans);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}