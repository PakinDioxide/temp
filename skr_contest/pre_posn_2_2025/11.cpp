/*
    author  : PakinDioxide
    created : 17/03/2025 21:32
    task    : 11
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll a[n][m];
    ll dis[n*m][n*m];
    for (int i = 0; i < n*m; i++) for (int j = 0; j < n*m; j++) dis[i][j] = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto p = [&] (int x, int y) {
        return m*x + y;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i+1 < n) dis[p(i, j)][p(i+1, j)] = a[i+1][j];
            if (i-1 >= 0) dis[p(i, j)][p(i-1, j)] = a[i-1][j];
            if (j+1 < m) dis[p(i, j)][p(i, j+1)] = a[i][j+1];
            if (j-1 >= 0) dis[p(i, j)][p(i, j-1)] = a[i][j-1];
        }
    }
    for (int i = 0; i < n*m; i++) dis[i][i] = 0;
    for (int k = 0; k < n*m; k++) {
        for (int i = 0; i < n*m; i++) {
            for (int j = 0; j < n*m; j++) {
                if (dis[i][k] == LLONG_MAX || dis[k][j] == LLONG_MAX) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]) dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int xx, yy, aa, bb;
        cin >> xx >> yy >> aa >> bb;
        xx--, yy--, aa--, bb--;
        cout << dis[p(xx, yy)][p(aa, bb)] << '\n';
    }
}