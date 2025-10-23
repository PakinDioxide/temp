#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long n, m, q;
    cin >> n >> m >> q;
    vector <vector <long long>> dis(n, vector <long long>(n, LLONG_MAX));
    for (long long i = 0; i < n; i++) dis[i][i] = 0;
    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        dis[u][v] = min(w, dis[u][v]);
        dis[v][u] = min(w, dis[v][u]);
    }
    for (long long k = 0; k < n; k++) {
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < n; j++) {
                if (dis[i][k] != LLONG_MAX && dis[k][j] != LLONG_MAX) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    for (long long i = 0; i < q; i++) {
        long long a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dis[a][b] == LLONG_MAX) cout << "-1\n";
        else cout << dis[a][b] << '\n';
    }
}