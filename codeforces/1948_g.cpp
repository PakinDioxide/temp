#include <bits/stdc++.h>

using namespace std;

int par[30];

int fi(int x) {
    if (par[x] != x) return par[x] = fi(par[x]);
    return par[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue <pair <int, pair <int, int>>> edge;
    for (int i = 0; i < n; i++) {
        par[i] = i;
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (j > i && w > 0) edge.emplace(-w, make_pair(i, j));
        }
    }
    int ans = 0, c = 0;
    while (!edge.empty() && c < n-1) {
        int w = -edge.top().first, u = edge.top().second.first, v = edge.top().second.second;
        edge.pop();
        if (fi(par[u]) != fi(par[v])) {
            par[fi(u)] = fi(par[v]);
            ans += w;
            c++;
        }
    }
    cout << ans << '\n';
}