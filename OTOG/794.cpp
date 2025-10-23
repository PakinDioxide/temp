/*
    author  : PakinDioxide
    created : 09/04/2025 20:28
    task    : 794
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, l, r;
unordered_map <ll, ll> vis, dp;

ll solve(ll x) {
    if (x < l+r) return 1;
    if (vis[x]) return dp[x];
    vis[x] = 1;
    return dp[x] = solve(x*l/(l+r)) + solve(x*r/(l+r));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> l >> r;
    cout << solve(n) << '\n';
}