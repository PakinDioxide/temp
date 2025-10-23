/*
    author  : 
    created : 17/06/2025 22:27
    task    : 2121E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

string l, r;
int dp[10][2][2], vis[10][2][2];

int solve(int idx, int lw, int rw) {
    if (vis[idx][lw][rw]) return dp[idx][lw][rw];
    vis[idx][lw][rw] = 1;
    // cout << idx << ' ' << lw << ' ' << rw << '\n';
    if (idx >= l.size()) return 0;
    int x = l[idx] - '0', y = r[idx] - '0';
    if (y < x) y += 10;
    // cout << x << ' ' << y << '\n';
    if (y-x >= 2 && !lw && !rw) return dp[idx][lw][rw] = 0;
    if (lw) return dp[idx][lw][rw] = (l[idx]-'0' == 9 ? 1 + solve(idx+1, lw, rw) : 0);
    else if (rw) return dp[idx][lw][rw] = (r[idx]-'0' == 0 ? 1 + solve(idx+1, lw, rw) : 0);
    else if (x == y) return dp[idx][lw][rw] = 2 + solve(idx+1, 0, 0);
    else return dp[idx][lw][rw] = min(solve(idx+1, 1, 0) + 1, solve(idx+1, 0, 1) + 1);
}

void solve() {
    cin >> l >> r;
    memset(vis, 0, sizeof(vis));
    cout << solve(0, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}