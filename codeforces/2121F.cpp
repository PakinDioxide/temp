/*
    author  : 
    created : 17/06/2025 23:17
    task    : 2121F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; ll s, x; cin >> n >> s >> x;
    ll a[n+1], p[n+1]; p[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i-1] + a[i];
    unordered_map <ll, pair <ll, ll>> cnt;
    int idx = 0; ll ans = 0;
    cnt[0] = make_pair(1, 0);
    for (int i = 1; i <= n;) {
        if (a[i] > x) { cnt[p[i]].second = i, cnt[p[i]].first = 1; idx = i; i++; continue; }
        int id = i;
        if (a[i] == x) {
            while (id <= n && (a[id] < x || id == i)) {
                ans += (cnt[p[id]-s].second < idx ? 0 : cnt[p[id]-s].first);
                id++;
            }
        } else id++;
        for (int j = i; j < id; j++) {
            if (cnt[p[j]].second < idx) cnt[p[j]].second = i, cnt[p[j]].first = 0;
            cnt[p[j]].first++;
        }
        i = id;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}