#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll r[n], c[m], a[n][m];
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j], r[i] += a[i][j], c[j] += a[i][j];
    }
    // for (int i = 0; i < n; i++) cout << "R : " << i << ' '<< r[i] << '\n';
    // for (int i = 0; i < m ;i++) cout << "C : " << i << ' ' << c[i] << '\n';
    char re = 0;
    int x = 0, y = 0;
    s += ' ';
    for (int i = 0; i < s.size()-1; i++) {
        // cout << x << ' ' << y << '\n';
        // cout << r[x] << ' '<< c[y] << '\n';
        if (s[i] == 'D') a[x][y] = -r[x], r[x] += a[x][y], c[y] += a[x][y];
        else a[x][y] = -c[y], r[x] += a[x][y], c[y] += a[x][y];
        if (s[i] == 'R') y++;
        else x++;
    }
    a[x][y] = -r[x];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}