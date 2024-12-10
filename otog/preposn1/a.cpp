#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[2005][2005];

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, q, ans = 0, no = 0;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    while (q--) {
        int x, y;
        char k;
        cin >> x >> y >> k;
        x++, y++;
        if (k == 'U') {
            x--;
        } else if (k == 'D') {
            x++;
        } else if (k == 'L') {
            y--;
        } else if (k == 'R') y++;
        if (x < 1 || x > n || y < 1 || y > m) no++;
        else ans += a[x][y];
        // cout << x << ' ' << y << ' ' << a[x][y] << '\n';
    }
    cout << ans << ' ' << no;
}