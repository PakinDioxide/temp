/*
    author  : PakinDioxide
    created : 28/03/2025 21:00
    task    : NOI18_collectmushrooms
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, d, k;
    cin >> n >> m >> d >> k;
    string a[n+1];
    int p[n+1][m+1];
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s = ' ' + s;
        a[i] = s;
        for (int j = 1; j <= m; j++) p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + (a[i][j] == 'S');
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (a[i][j] != 'M') continue;
        int x1 = max(1, i-d), x2 = min(n, i+d), y1 = max(1, j-d), y2 = min(m, j+d);
        cnt += (p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1] >= k);
    }
    cout << cnt << '\n';
}