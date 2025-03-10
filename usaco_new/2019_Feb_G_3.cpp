#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[205][205];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        int p, q, x, y;
        cin >> p >> q >> x >> y;
        p++, q++, x++, y++;
        for (int i = p; i <= x; i++) for (int j = q; j <= y; j++) a[i][j]++;
    }
    int dp[205][205][3];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 201; i++) for (int j = 1; j <= 201; j++) {
        dp[i][j][0] = dp[i-1][j][0] + dp[i][j-1][0] - dp[i-1][j-1][0];
        dp[i][j][1] = dp[i-1][j][1] + dp[i][j-1][1] - dp[i-1][j-1][1];
        dp[i][j][2] = dp[i-1][j][2] + dp[i][j-1][2] - dp[i-1][j-1][2];
        if (a[i][j] ==  k-2) dp[i][j][0]++;
        else if (a[i][j] == k-1) dp[i][j][1]++;
        else if (a[i][j] == k) dp[i][j][2]++;
    }
}

/*
1111....
1111....
1122111.
1122111.
..11111.
..11111.
........
........
*/