#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;

    vector <set <int>> adj(n+1);

    vector <int> dis(n+1, INT_MAX), prev(n+1);
    dis[1] = 0;
    prev[1] = -1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    queue <int> q;

    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto i : adj[x]) {
            if (dis[i] == INT_MAX) {
                dis[i] = dis[x] + 1;
                prev[i] = x;
                q.push(i);
            }
        }
    }

    if (dis[n] == INT_MAX) cout << "IMPOSSIBLE";
    else {
        cout << dis[n] + 1 << '\n';
        vector <int> path;

        int k = n;

        while (k != -1) {
            path.push_back(k);
            k = prev[k];
        }

        for (int i = path.size()-1; i >= 0; i--) cout << path[i] << ' ';
    }
}
