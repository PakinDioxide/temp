#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q, s;
    cin >> n >> q;
    s = sqrt(n);
    int a[n], dp[s+1][n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int k = n-1; k > 0; k--) {
        for (int i = 0; i < n; i++) {
            if (i+k >= n) dp[k][i] = dp[n][i];
            else dp[k][i] = dp[min(n, 2*k)][i] + dp[min(n, 2*k)][i+k];
        }
    }
    while (q--) {
        int l, r, m;
        cin >> l >> m >> r;
        l--;
        if ((r-l)%m != 0) r += (m-(r-l)%m);
        if (r >= n) cout << dp[m][l] << ' ';
        else cout << dp[m][l] - dp[m][r] << ' ';
    }
}

/*
q - - - - q - - - - q -
*/