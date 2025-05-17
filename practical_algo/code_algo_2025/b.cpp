/*
    author  : PakinDioxide
    created : 02/05/2025 00:40
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7;

int dp[2][5005];
vector <pair <int, int>> v;
set <pair <int, int>> s;
map <pair <int, int>, int> mp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    v.resize(q);
    for (auto &[x, y] : v) cin >> x >> y, s.emplace(x, y);
    auto it = s.begin();
    for (int i = 0; i <= 100000; i++) for (int j = 0; j <= min(5000, i); j++) {
        if (i == 0 || j == 0 || i == j) dp[i&1][j] = 1;
        else dp[i&1][j] = dp[!(i&1)][j-1] + dp[!(i&1)][j];
        dp[i&1][j] %= mod;
        if (*it == make_pair(i, j)) mp[{i, j}] = dp[i&1][j], it++;
        if (it == s.end()) break;
    }
    for (auto &[x, y] : v) cout << mp[{x, y}] << '\n';
}