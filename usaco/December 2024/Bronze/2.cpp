#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q, ans = 0;
    cin >> n >> q;
    int xc[n][n], yc[n][n], zc[n][n], vxc[n][n], vyc[n][n], vzc[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) xc[i][j] = yc[i][j] = zc[i][j] = n, vxc[i][j] = vyc[i][j] = vzc[i][j] = 1;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        xc[y][z]--, yc[x][z]--, zc[x][y]--;
        if (!xc[y][z]) ans += vxc[y][z], vxc[y][z] = 0;
        if (!yc[x][z]) ans += vyc[x][z], vyc[x][z] = 0;
        if (!zc[x][y]) ans += vzc[x][y], vzc[x][y] = 0;
        cout << ans << '\n';
    }
}