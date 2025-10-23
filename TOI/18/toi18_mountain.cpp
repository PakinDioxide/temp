#include <bits/stdc++.h>

using namespace std;

long long n, m, dis[505][505];

int main() {
    scanf("%lld %lld", &n, &m);
    pair <long long, long long> g[n];
    for (long long i = 0; i < n; i++) scanf("%lld %lld", &g[i].first, &g[i].second);
    for (long long i = 0; i < n; i++) for (long long j = 0; j < n; j++) dis[i][j] = LLONG_MAX;
    dis[0][0] = 0;
    for (long long f = 1; f < n; f++) {
        for (long long u = 0; u < n; u++) {
            for (long long v = 0; v < n; v++) {
                if (u == v) continue;
                dis[u][f] = min(dis[u][f], max(dis[v][f-1], abs(g[u].first - g[v].first) + abs(g[u].second - g[v].second)));
            }
        }
    }
    long long ans = 0;
    while (m--) {
        long long x;
        scanf("%lld", &x);
        for (long long f = 1; f < n; f++) if (dis[n-1][f] <= x) {ans += f; break;}
    }
    printf("%lld", ans);
}