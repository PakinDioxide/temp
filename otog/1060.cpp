#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k; ll x;
    cin >> n >> k;
    map <int, multiset <ll>> dp;
    vector <pair <ll, int>> a[n];
    for (int i = 0; i < n; i++) for (int j = i; j < n; j++) cin >> x, a[j].emplace_back(x, i);
    dp[-1].emplace(0), dp[-2].emplace(0);
    for (int i = 0; i < n; i++) {
        dp[i] = dp[i-1];
        for (auto &[e, j] : a[i]) for (auto &ee : dp[j-2]) {dp[i].emplace(ee+e); if (dp[i].size() > k) dp[i].erase(dp[i].begin());}
    }
    deque <ll> ans;
    for (auto &e : dp[n-1]) ans.emplace_front(e);
    for (auto &e : ans) cout << e << ' ';
    cout << '\n';
}