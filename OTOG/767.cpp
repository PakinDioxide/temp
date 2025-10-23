#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int m, x, y, z, ni[3];
    cin >> m >> x >> y >> z;
    vector <int> a[3];
    for (int i = 0; i < 3; i++) {
        cin >> ni[i];
        a[i].resize(ni[i]+1);
        for (int j = 1; j <= ni[i]; j++) cin >> a[i][j];
        ni[i]++;
        a[i].push_back(LLONG_MIN);
    }
    int dp[ni[0]+1][ni[1]+1][ni[2]+1];
    for (int i = 0; i <= ni[0]; i++) for (int j = 0; j <= ni[1]; j++) for (int k = 0; k <= ni[2]; k++) dp[i][j][k] = LLONG_MIN;
    dp[1][1][1] = 0;
    for (int i = 1; i <= ni[0]; i++) for (int j = 1; j <= ni[1]; j++) for (int k = 1; k <= ni[2]; k++) {
        if (dp[i][j][k] == LLONG_MIN) continue;
        if (i != ni[0] && j != ni[1] && k != ni[2] && a[0][i] == a[1][j] && a[0][i] == a[2][k]) dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k] - m + z);
        else if ((i != ni[0] && j != ni[1] && a[0][i] == a[1][j]) || (i != ni[0] && k != ni[2] && a[0][i] == a[2][k]) || (j != ni[1] && k != ni[2] && a[1][j] == a[2][k])) {
            if (i != ni[0] && j != ni[1] && a[0][i] == a[1][j]) {dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] - m + y); if (k != ni[2]) dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k] - m + x);}
            if (i != ni[0] && k != ni[2] && a[0][i] == a[2][k]) {dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] - m + y); if (j != ni[1]) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k] - m + x);}
            if (j != ni[1] && k != ni[2] && a[1][j] == a[2][k]) {dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] - m + y); if (i != ni[0]) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] - m + x);}
        } else {
            if (i != ni[0]) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] - m + x);
            if (j != ni[1]) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k] - m + x);
            if (k != ni[2]) dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k] - m + x);
        }
    }
    cout << dp[ni[0]][ni[1]][ni[2]] << '\n';
}


int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}