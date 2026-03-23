#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k; cin >> n >> k;
    map <int, set <pair <ll, ll>>> mp;
    for (int i = 0; i < n; i++) {
        int t; ll x, y, c; cin >> t >> x >> y >> c;
        if (t == 1 || t == 2) mp[t].emplace(x, c);
        else mp[t].emplace(y, c);
    }
    ll ans = 0;
    while (k--) {
        ll mn = LLONG_MAX;
        for (auto &[e1, c1] : mp[1]) {
            for (auto &[e2, c2] : mp[2]) {
                if (e1 < e2) continue;
                mn = min(mn, c1+c2);
            }
        }
        for (auto &[e1, c1] : mp[3]) {
            for (auto &[e2, c2] : mp[4]) {
                if (e1 < e2) continue;
                mn = min(mn, c1+c2);
            }
        }
        if (mn == LLONG_MAX) { cout << -1 << '\n'; return 0; }
        int ok = 0;
        for (auto &[e1, c1] : mp[1]) {
            if (ok) break;
            for (auto &[e2, c2] : mp[2]) {
                if (ok) break;
                if (e1 < e2 || c1 + c2 > mn) continue;
                mp[1].erase(mp[1].find(make_pair(e1, c1)));
                mp[2].erase(mp[2].find(make_pair(e2, c2)));
                ok = 1;
            }
        }
        for (auto &[e1, c1] : mp[3]) {
            if (ok) break;
            for (auto &[e2, c2] : mp[4]) {
                if (ok) break;
                if (e1 < e2 || c1 + c2 > mn) continue;
                mp[3].erase(mp[3].find(make_pair(e1, c1)));
                mp[4].erase(mp[4].find(make_pair(e2, c2)));
                ok = 1;
            }
        }
        ans += mn;
    }
    cout << ans << '\n';
}
