/*
    author  : PakinDioxide
    created : 17/03/2025 21:56
    task    : 01
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> a[1000005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, e;
        cin >> x;
        for (int j = 0; j < x; j++) cin >> e, a[e].push_back(i);
    }
    int dis[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dis[i][j] = (i == j ? 0 : INT_MAX);
    for (int i = 0; i < 1000005; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            for (int k = 1; k < a[i].size(); k++) {
                if (a[i][j] == a[i][k]) continue;
                dis[a[i][j]][a[i][k]] = dis[a[i][k]][a[i][j]] = 1;
            }
        }
    }
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) continue;
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    int s, t, ans = INT_MAX;
    cin >> s >> t;
    for (auto &p : a[s]) for (auto &q : a[t]) ans = min(ans, dis[p][q]);
    if (s == t) cout << 0 << '\n';
    else cout << (ans == INT_MAX ? -1 : ans+1) << '\n';
}