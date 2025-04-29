/*
    author  : PakinDioxide
    created : 27/04/2025 13:08
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int a[mxN], b[mxN];
unordered_map <int, vector <int>> mp;

void solve() {
    int n, m;
    cin >> n >> m;
    mp.clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i], mp[b[i]].emplace_back(i);
    ll ans = 0; int idx = 1;
    for (int i = 1; i <= n; i++) {
        int e = a[i];
        auto it = lower_bound(mp[e].begin(), mp[e].end(), idx);
        if (it == mp[e].end()) it = lower_bound(mp[e].begin(), mp[e].end(), 1), ans += m-idx+*it, idx = *it;
        else ans += *it - idx, idx = *it;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}