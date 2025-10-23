/*
    author  : 
    created : 15/06/2025 16:27
    task    : 2113C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 505;

char a[mxN][mxN]; int p[mxN][mxN];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++) a[i][j] = p[i][j] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'g') p[i][j] = 1;
    }
    for (int i = 1; i <= n+1; i++) for (int j = 1; j <= m+1; j++) p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    auto calc = [&] (int x1, int y1, int x2, int y2) {
        x1 = max(x1, 1), x2 = min(x2, n+1), y1 = max(y1, 1), y2 = min(y2, m+1);
        return p[x2][y2] - p[x2][y1-1] - p[x1-1][y2] + p[x1-1][y1-1];
    };
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] == '.') {
        mn = min(mn, calc(i-k+1, j-k+1, i+k-1, j+k-1));
    }
    if (mn == INT_MAX) mn = p[n][m];
    cout << p[n][m] - mn << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}