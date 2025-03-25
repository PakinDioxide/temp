/*
    author  : PakinDioxide
    created : 22/03/2025 20:01
    task    : ball
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[25][25], dp[25][1 << 20];

ll solve(int idx, ll vis) {
    if (idx == n) return 0;
    if (dp[idx][vis] > 0) return dp[idx][vis];
    for (int i = 0; i < n; i++) {
        if (vis & (1 << i)) continue;
        dp[idx][vis] = max(dp[idx][vis], solve(idx+1, vis | (1 << i)) + a[idx][i]);
    }
    return dp[idx][vis];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    cout << solve(0, 0) << '\n';
}