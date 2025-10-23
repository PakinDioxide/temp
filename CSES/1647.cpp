/*
    author  : PakinDioxide
    created : 08/04/2025 01:45
    task    : 1647
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;
int n, q, dp[20][mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> dp[0][i];
    for (int i = 1; i < 20; i++) for (int j = 0; j + (1 << i) <= n; j++) dp[i][j] = min(dp[i-1][j], dp[i-1][j + (1 << (i-1))]);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int d = r-l, ans = INT_MAX;
        for (int i = 0; i < 20; i++) if (d & (1 << i)) ans = min(ans, dp[i][l]), l += (1 << i);
        cout << ans << '\n';
    }
}

/*
    https://cp-algorithms.com/data_structures/sparse-table.html
*/