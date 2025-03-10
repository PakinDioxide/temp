#include <bits/stdc++.h>

using namespace std;

vector <int> adj[500005];
int co[500005], cnt[500005];

void dfs(int u) {
    for (int v : adj[u]) {
        co[v] = co[u] + 1;
        cnt[co[v]]++;
        dfs(v);
    }
}

void solve() {
    int n, u, v;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) adj[i].clear(), co[i] = cnt[i] = 0;
    for (int i = 1; i < n; i++) scanf("%d %d", &u, &v), adj[u].push_back(v);
    dfs(1);
    int mx = 0, c = 0, ans = 0;
    for (int i = 0; i < n; i++) if (cnt[i] >= mx) cnt[i] = mx, c = i;
    for (int i = 1; i <= n; i++) {if (co[i] > c) ans++; printf("%d ", co[i]);}
    printf("\n");
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}