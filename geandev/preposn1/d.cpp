#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[100005][26];

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    map <int, vector <int>> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;
        int ll = lower_bound(mp[x].begin(), mp[x].end(), l) - mp[x].begin();
        int rr = upper_bound(mp[x].begin(), mp[x].end(), r) - mp[x].begin();
        cout << rr - ll << '\n';
    }
}