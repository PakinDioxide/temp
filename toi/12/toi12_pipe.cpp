/*
    author  : PakinDioxide
    created : 03/05/2025 09:52
    task    : toi12_pipe
*/
#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
#pragma target ("avx2")

using namespace std;

const int mxN = 15000;

int n, k, dist[mxN], ans = 0, x[mxN], y[mxN];
vector <int> V;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) dist[i] = INT_MAX - 1, cin >> x[i] >> y[i];
    dist[0] = 0;
    for (int t = 0; t < n; t++) {
        int u = 0, mn = INT_MAX;
        for (int i = 0; i < n; i++) if (dist[i] < mn) mn = dist[i], u = i;
        V.emplace_back(mn);
        dist[u] = INT_MAX;
        for (int v = 0; v < n; v++) if (dist[v] != INT_MAX) dist[v] = min(dist[v], abs(x[u]-x[v]) + abs(y[u] - y[v]));
    }
    sort(V.begin(), V.end());
    for (int i = 1; i <= n-k; i++) ans += V[i];
    cout << ans << '\n';
}