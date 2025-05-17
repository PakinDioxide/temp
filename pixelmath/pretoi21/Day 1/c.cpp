#include <bits/stdc++.h>
#define ll long double

using namespace std;

const int mxN = 560;

int n, m, q;
ll dis[mxN][mxN], cnt = 0;
vector <tuple <int, int, ll>> E;
vector <tuple <ll, int, int>> Q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = LDBL_MAX;
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 0; i < m; i++) { int u, v; ll w; cin >> u >> v >> w; dis[u][v] = min(dis[u][v], w); dis[v][u] = min(dis[v][u], w); E.emplace_back(u, v, w); }
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (dis[i][k] < LDBL_MAX && dis[k][j] < LDBL_MAX) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 0; i < q; i++) { int u, v; ll w; cin >> u >> v >> w; if (dis[u][v] <= w) Q.emplace_back(-w, u, v); }
    sort(Q.begin(), Q.end());
    for (auto &[u, v, w] : E) for (auto &[x, a, b] : Q) if (dis[a][u] + w + dis[v][b] <= -x || dis[a][v] + w + dis[u][b] <= -x) { cnt++; break; }
    cout << fixed << setprecision(0) << cnt << '\n';
}