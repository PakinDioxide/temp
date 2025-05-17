/*
    author  : PakinDioxide
    created : 27/04/2025 13:13
    task    : c
*/
#include <bits/stdc++.h>
// #define ll long long
#define ll int

using namespace std;

const int mxN = 5005;

pair <pair <ll, ll>, pair <ll, ll>> a[mxN];

void solve() {
    int n, m, k, idx = 0;
    cin >> n >> m >> k;
    map <pair <ll, ll>, int> mp;
    unordered_map <int, pair <ll, ll>> mp2;
    vector <vector <int>> dis(2*k+5, vector <int>(2*k+5, INT_MAX));
    vector <int> adj[2*k+5];
    for (int i = 1; i <= k; i++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
        if (!mp[a[i].first]) mp[a[i].first] = ++idx, mp2[idx] = a[i].first;
        if (!mp[a[i].second]) mp[a[i].second] = ++idx, mp2[idx] = a[i].second;
        adj[mp[a[i].first]].emplace_back(mp[a[i].second]);
        adj[mp[a[i].second]].emplace_back(mp[a[i].first]);
        // dis[mp[a[i].first]][mp[a[i].second]] = dis[mp[a[i].second]][mp[a[i].first]] = 1;
    }
    for (int i = 1; i <= idx; i++) {
        queue <int> q;
        dis[i][i] = 0;
        q.emplace(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : adj[u]) if (dis[i][v] > dis[i][u] + 1) q.emplace(v), dis[i][v] = dis[i][u]+1;
        }
    }
    // for (int k = 1; k <= idx; k++) {
    //     for (int i = 1; i <= idx; i++) {
    //         for (int j = 1; j <= idx; j++) {
    //             if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) continue;
    //             dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    //         }
    //     }
    // }
    int q;
    cin >> q;
    auto calc = [&] (ll sx, ll sy, ll ex, ll ey) { return (ll) abs(sx-ex) + abs(sy-ey); };
    while (q--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        ll mn = calc(sx, sy, ex, ey);
        if (k == 0) {cout << mn << '\n'; continue;}
        deque <pair <int, int>> q;
        vector <int> dis(idx+1, INT_MAX);
        // do a 0/1 bfs
        q.emplace(0, 1);
        dis[1] = 0;
        while (!q.empty()) {
            int w, u;
            tie(w, u) = q.front();
            if (dis[u] != w) q.pop();
        }
        cout << mn << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}