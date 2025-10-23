#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    int p[n+1], zr[30][n+1], on[30][n+1];
    p[0] = 0;
    for (int i = 0; i < 30; i++) zr[i][0] = on[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p[i] = p[i-1] + x;
        for (int j = 0; j < 30; j++) {
            zr[j][i] = zr[j][i-1] + ((x & (1LL << j)) == 0);
            on[j][i] = on[j][i-1] + ((x & (1LL << j)) > 0);
            // cout << on[j][i] << ' ';
        }
        // cout << '\n';
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        int sum = p[r] - p[l];
        for (int i = 0; i < 30; i++) {
            if (x & (1LL << i)) {
                sum += (zr[i][r] - zr[i][l])*(1LL << i) - (on[i][r] - on[i][l])*(1LL << i);
                // cout << (zr[i][r] - zr[i][l])*(1LL << i) << ' ' << (on[i][r] - on[i][l]) << '\n';
            }
            // cout << x << ' ' << i << ' ' << sum << '\n';
        }
        cout << sum << '\n';
    }
}

// 1001