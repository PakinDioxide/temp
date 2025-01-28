// sol o(n^2) - AC
#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int>> adj[100005];
int pr[100005][2], dep[100005];

void dfs(int u, int p) {
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u]+1;
        pr[v][0] = u, pr[v][1] = w;
        dfs(v, u);
    }
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int pos[n+5], par[n+5];
    for (int i = 1; i <= n; i++) cin >> pos[i], par[i] = i;
    vector <tuple <int, int, int>> E(m), e;
    for (auto &[w, u, v] : E) cin >> u >> v >> w;
    sort(E.begin(), E.end());
    function <int(int)> fi = [&] (int x) {
        if (par[x] != x) return par[x] = fi(par[x]);
        return x;
    };
    for (int i = m-1; i >= 0; i--) {
        auto [w, u, v] = E[i];
        if (fi(u) == fi(v)) continue;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        par[fi(u)] = fi(v);
    }
    dfs(1, 0);
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (pos[i] == i) continue;
        int u = pos[i], v = i;
        if (dep[u] < dep[v]) swap(u, v);
        while (dep[u] > dep[v]) ans = min(ans, pr[u][1]), u = pr[u][0];
        while (u != v) ans = min({ans, pr[u][1], pr[v][1]}), u = pr[u][0], v = pr[v][0];
    }
    cout << (ans == INT_MAX ? -1 : ans);
}

// // sol o(nlogn) - AC (slower than o(n^2)) WTF
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     freopen("wormsort.in", "r", stdin);
//     freopen("wormsort.out", "w", stdout);
//     int n, m;
//     cin >> n >> m;
//     int pos[n+5];
//     for (int i = 1; i <= n; i++) cin >> pos[i];
//     vector <tuple <int, int, int>> E(m);
//     for (auto &[w, u, v] : E) cin >> u >> v >> w;
//     sort(E.begin(), E.end());
//     int l = 0, r = 1e9+5, ans = 0;
//     while (l <= r) {
//         int mid = l + (r-l)/2;
//         int par[n+5];
//         iota(par+1, par+n+1, 1);
//         function <int(int)> fi = [&] (int x) {
//             if (x != par[x]) return par[x] = fi(par[x]);
//             return x;
//         };
//         for (int i = m-1; i >= 0; i--) {
//             auto [w, u, v] = E[i];
//             if (w < mid) continue;
//             if (fi(u) == fi(v)) continue;
//             par[fi(u)] = fi(v);
//         }
//         int ok = 1;
//         for (int i = 1; i <= n; i++) if (fi(i) != fi(pos[i])) {ok = 0; break;}
//         if (ok) ans = mid, l = mid+1;
//         else r = mid-1;
//     }
//     cout << (ans == 1e9+5 ? -1 : ans) << '\n';
// }