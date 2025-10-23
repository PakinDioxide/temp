#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    char a[n][m];
    string dir[3][3] = {{" ", "U", " "}, {"L", " ", "R"}, {" ", "D", " "}};
    int vis[n][m];
    for (int i = 0; i < n; i++) cin >> a[i];
    queue <pair <pair <int, int>, string>> q;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {vis[i][j] = 0; if (a[i][j] == 'A') sx = i, sy = j;};
    q.emplace(make_pair(make_pair(sx, sy), ""));
    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        string k = q.front().second;
        q.pop();
        if (a[x][y] == 'B') {
            cout << "YES\n";
            cout << k.size() << '\n';
            cout << k;
            return 0;
        }
        // cout << x << ' ' << y << '\n';
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (x+i < 0 || x+i >= n || y+j < 0 || y+j >= m || a[x+i][y+j] == '#' || vis[x+i][y+j] || (i != 0 && j != 0) || (i == 0 && j == 0)) continue;
                q.emplace(make_pair(make_pair(x+i, y+j), k + dir[i+1][j+1]));
            }
        }
    }
    cout << "NO";
}