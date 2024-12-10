#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector <vector <pair <long long, long long>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue <pair <long long, long long>> q;
    vector <long long> dis(n+1, LLONG_MAX);
    vector <bool> vis(n+1);
    dis[1] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        long long x = q.top().second;
        q.pop();

        if (vis[x]) continue;
        vis[x] = true;

        for (auto u : adj[x]) {
            long long b = u.first, w = u.second;

            if (dis[x] + w < dis[b]) {
                dis[b] = dis[x] + w;
                q.push({-dis[b], b});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
}
