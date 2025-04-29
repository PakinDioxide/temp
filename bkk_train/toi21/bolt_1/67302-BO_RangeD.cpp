#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

    ll p[2005][2005], p2[2005][2005], p3[2005];

void solve() {
    int n, q;
    cin >> n >> q;
    ll a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) for (int j = n; j >= 1; j--) p[i][j] = p[i][j+1] + (j > i ? a[j]/a[i] : 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p2[i][j] = p2[i-1][j] + p[i][j];
        }
    }
    for (int i = 1; i <= n; i++) p3[i] = p[i][i] + p3[i-1];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << p3[r] - p3[l-1] - (p2[r][r+1] - p2[l-1][r+1]) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    while (t--) solve();
}

/*
given l, r
we want to find p[i][i] - p[i][l-1] for all i = l to r
*/