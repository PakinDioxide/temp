#include <bits/stdc++.h>
#define ll unsigned int

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

const ll mod = 1e9+7;
const int mxN = 505;

ll dp[2][mxN][mxN][3], n, a, b, c, ans = 0;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> a >> b >> c;
    for (int z = 0; z < 3; z++) {
        for (int i = 0; i < 2; i++) for (int p = 0; p <= b; p++) for (int q = 0; q <= c; q++) for (int z = 0; z < 3; z++) dp[i&1][p][q][z] = 0;
        if (z == 0) dp[0][0][0][0] = 1;
        else if (z == 1) dp[0][0][0][1] = 1;
        else dp[0][0][0][2] = 1;
        for (int i = 3; i < n-1; i++) {
            // for (int p = 0; p <= b; p++) for (int q = 0; q <= c; q++) for (int z = 0; z < 3; z++) dp[i&1][p][q][z] = 0;
            // cout << i << '\n';
            for (int p = 0; p <= b; p++) for (int q = 0; q <= c; q++) {
                dp[i&1][p][q][0] = (dp[!(i&1)][p][q][1] + dp[!(i&1)][p][q][2]) % mod;
                if (p >= 1) dp[i&1][p][q][1] = (dp[!(i&1)][p-1][q][0] + dp[!(i&1)][p-1][q][2]) % mod;
                else dp[i&1][p][q][1] = 0;
                if (q >= 1) dp[i&1][p][q][2] = (dp[!(i&1)][p][q-1][0] + dp[!(i&1)][p][q-1][1]) % mod;
                else dp[i&1][p][q][2] = 0;
            }
            // for (int p = 0; p <= b; p++) { for (int q = 0; q <= c; q++) cout << dp[i&1][p][q][0] << ' '; cout << '\n'; }
        }
        // cout << dp[(n-2)&1][Q][R][0] + dp[(n-2)&1][Q][R][1] + dp[(n-2)&1][Q][R][2] - dp[(n-2)&1][Q][R][z] << '\n';
        // ans += dp[(n-2)&1][Q][R][0] + dp[(n-2)&1][Q][R][1] + dp[(n-2)&1][Q][R][2] - dp[(n-2)&1][Q][R][z];
        // ans %= mod;
        for (int x = 0; x < 3; x++) for (int y = 0; y < 3; y++) if (x != y && y != z && z != x) {
            int P = a - (x == 0) - (y == 0) - 2*(z == 0), Q = b - (x == 1) - (y == 1) - 2*(z == 1), R = c - (x == 2) - (y == 2) - 2*(z == 2);
            if (P < 0 || Q < 0 || R < 0) continue;
            ans += dp[(n-2)&1][Q][R][0] + dp[(n-2)&1][Q][R][1] + dp[(n-2)&1][Q][R][2] - dp[(n-2)&1][Q][R][z];
            ans %= mod;
        }
    }
    cout << ans << '\n';
}

/*
1 != 2, 2 != 3, 3 != 4, .. N-1 != N

1 != 2
1 != 3
1 != N
2 != N

if 1 = x, 2 = y

then N = z
3 = z

do dp
*/