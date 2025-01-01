#include <bits/stdc++.h>

using namespace std;

struct E {
    int x, y, k, l;
    bool operator<(const E &q) const {
        return x == q.x ? y < q.y : x < q.x;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int sx, sy, n;
    cin >> sx >> sy >> n;
    int a[4][n][2];
    E v[n*n];
    for (int i = 0; i < 4; i++) for (int j = 0; j < n; j++) cin >> a[i][j][0] >> a[i][j][1];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) v[n*i+j] = {a[2][i][0] + a[3][j][0], a[2][i][1] + a[3][j][1], i, j};
    sort(v, v+n*n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int x = sx-a[0][i][0]-a[1][j][0], y = sy-a[0][i][1]-a[1][j][1];
        int idx = n*n, l = 0, r = n*n-1, mid;
        while (l <= r) {
            mid = (l+r)/2;
            if (x < v[mid].x) r = mid-1;
            else if (x == v[mid].x) {
                if (y < v[mid].y) r = mid-1;
                else if (y == v[mid].y) {idx = mid; break;}
                else l = mid+1;
            } else l = mid+1;
        }
        if (idx != n*n) {
            int k = v[idx].k, l = v[idx].l;
            cout << a[0][i][0] << ' ' << a[0][i][1] << '\n' << a[1][j][0] << ' ' << a[1][j][1] << '\n' << a[2][k][0] << ' ' << a[2][k][1] << '\n' << a[3][l][0] << ' ' << a[3][l][1];
            return 0;
        }
    }
}