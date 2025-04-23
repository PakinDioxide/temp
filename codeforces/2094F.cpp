/*
    author  : PakinDioxide
    created : 13/04/2025 23:03
    task    : 2094F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    int a[n][m], cnt = n*m/k;
    int ox = 0, oy = m-1, ex = 0, ey = m-2;
    int kd = 0;
    if (oy < 0) ox -= oy, oy = 0;
    if (ey < 0) ex -= ey, ey = 0;
    if ((int)ceil(n*m/2.0)%cnt != 0) {
        kd += (int)ceil(n*m/2.0)%cnt;
    }
    for (int i = 0; i < kd; i++) {
        ex++, ey++;
        if (ex == n || ey == m) ey = ey-ex-2, ex = 0;
        if (ey < 0) ex -= ey, ey = 0;
    }
    for (int e = 1; e <= k; e++) {
        if (e % 2 == 1) {
            for (int i = 0; i < cnt; i++) {
                // cout << "OX " << ox << ' ' << oy << '\n';
                a[ox][oy] = e;
                ox++, oy++;
                if (ox >= n || oy >= m) oy = oy-ox-2, ox = 0;
                if (oy < 0) ox -= oy, oy = 0;
                if (ox >= n) break;
            }
        } else {
            for (int i = 0; i < cnt; i++) {
                // cout << "EX " << ex << ' ' << ey << '\n';
                a[ex][ey] = e;
                ex++, ey++;
                if (ex >= n || ey >= m) ey = ey-ex-2, ex = 0;
                if (ey < 0) ex -= ey, ey = 0;
            }
        }
    }
    ex = 0, ey = m-2;
    if (ey < 0) ex -= ey, ey = 0;
    for (int i = 0; i < kd; i++) {
        // cout << "EX " << ex << ' ' << ey << '\n';
        a[ex][ey] = k;
        ex++, ey++;
        if (ex >= n || ey >= m) ey = ey-ex-2, ex = 0;
        if (ey < 0) ex -= ey, ey = 0;
    }
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