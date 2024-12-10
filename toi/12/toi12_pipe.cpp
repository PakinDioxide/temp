#include <bits/stdc++.h>

using namespace std;

int par[16000], r[16000];

int fi(int x) {
    if (par[x] != x) par[x] = fi(par[x]);
    return par[x];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) par[i] = i;
    pair <int, int> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    priority_queue <pair <int, pair <int, int>>> q;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            q.emplace(-abs(a[i].first - a[j].first) - abs(a[i].second - a[j].second), make_pair(i, j));
        }
    }
    int ans = 0, c = n-1;
    while (!q.empty() && c > 0) {
        int u = q.top().second.first, v = q.top().second.second, w = -q.top().first;
        q.pop();
        if (fi(par[u]) != fi(par[v])) {
            if (r[fi(par[u])] > r[fi(par[v])]) {
                par[fi(v)] = fi(par[u]);
            } else {
                par[fi(u)] = fi(par[v]);
                if (r[fi(u)] == r[fi(v)]) r[v]++;
            }
            if (c > m-1) ans += w;
            c--;
        }
    }
    cout << ans;
}