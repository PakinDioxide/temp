/*
    author  : 
    created : 12/07/2025 22:43
    task    : APIO14_sequence
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5, mxK = 205;

int n, k, par[mxK][mxN];
ll dp[2][mxN], p[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i], p[i] += p[i-1];
    for (int i = 1; i <= n; i++) dp[1][i] = p[i]*(p[n] - p[i]);
    for (int c = 2; c <= k; c++) {
        deque <int> cht; int sz = 0;
        cht.emplace_back(c-1), sz++;
        auto calc = [&] (int j, ll x) { return p[j]*x + -p[j]*p[n] + dp[!(c&1)][j]; };
        auto m = [&] (int x, int y) { return (double) (calc(x, 0) - calc(y, 0)) / (p[y] - p[x]); };
        for (int i = c; i <= n; i++) {
            while (sz > 1 && calc(cht[0], p[i]) <= calc(cht[1], p[i])) cht.pop_front(), sz--;
            dp[c&1][i] = p[i]*(p[n]-p[i]) + calc(cht[0], p[i]);
            par[c][i] = cht[0];
            while (sz > 0 && p[cht[sz-1]] == p[i] && calc(cht[sz-1], 0) <= calc(i, 0)) cht.pop_back(), sz--;
            while (sz > 1 && m(cht[sz-1], i) <= m(cht[sz-1], cht[sz-2])) cht.pop_back(), sz--;
            cht.emplace_back(i), sz++;
        }
    }
    ll mx = 0, idx = -1;
    for (int i = k; i < n; i++) if (dp[k&1][i] >= mx) mx = dp[k&1][i], idx = i;
    cout << mx << '\n';
    for (int i = k; i > 0; i--) cout << idx << ' ', idx = par[i][idx];
    cout << '\n';
}

/*
dp[c][i] = max((p[i] - p[j])*(p[n] - p[i]) + dp[c-1][j])
         = p[i]*(p[n]-p[i]) + max(p[j](p[i]) + -p[j]*p[n] + dp[c-1][j])
*/