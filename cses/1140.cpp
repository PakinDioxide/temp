#include <bits/stdc++.h>

using namespace std;

int n;
map <pair <int, int>, int> dp, vis;
vector <vector <int>> a;

int solve(int c, int p) {
    if (c == n) return 0;
    if (vis[{c, p}]) return dp[{c, p}];
    vis[{c, p}] = 1;
    int m = 0;
    if (p < a[c][1]) m = max(m, a[c][2] + solve(c+1, a[c][0]));
    m = max(m, solve(c+1, p));
    return dp[{c, p}] = m;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    a.resize(n, vector <int>(3));
    for (int i = 0; i < n; i++) cin >> a[i][1] >> a[i][0] >> a[i][2];
    sort(a.begin(), a.end());
    cout << solve(0, -1);
}