/*
    author  : PakinDioxide
    created : 27/03/2025 19:14
    task    : rose
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int a[n][m];
    memset(a, 0, sizeof(a));
    for (int o = 0; o < q; o++) {
        int x, y, k;
        cin >> x >> y >> k;
        a[x][y] = 2;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (abs(x-i) + abs(y-j) <= k) a[i][j] = max(a[i][j], 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << (a[i][j] == 0 ? '.' : a[i][j] == 1 ? '*' : '#');
        cout << '\n';
    }
}