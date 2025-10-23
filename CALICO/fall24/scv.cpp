#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    int dis[4][2];
    dis[0][0] = n, dis[0][1] = m, dis[1][0] = n, dis[1][1] = -1, dis[2][0] = -1, dis[2][1] = m, dis[3][0] = -1, dis[3][1] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (i < dis[0][0]) dis[0][0] = i, dis[0][1] = j;
                else if (i == dis[0][0]) dis[0][1] = min(dis[0][1], j);

                if (i < dis[1][0]) dis[1][0] = i, dis[1][1] = j;
                else if (i == dis[1][0]) dis[1][1] = max(dis[1][1], j);

                if (i > dis[2][0]) dis[2][0] = i, dis[2][1] = j;
                else if (i == dis[2][0]) dis[2][1] = min(dis[2][1], j);

                if (i > dis[3][0]) dis[3][0] = i, dis[3][1] = j;
                else if (i == dis[3][0]) dis[3][1] = max(dis[3][1], j);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        // cout << dis[i][0] << ' ' << dis[i][1] << '\n';
        for (int j = i+1; j < 4; j++) {
            if (dis[i][0] == dis[j][0] && dis[i][1] == dis[j][1]) cnt++;
        }
    }
    if (cnt == 0 || cnt == 2) cout << "ferb\n";
    else cout << "phineas\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}