#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k, p, m; cin >> n >> k >> p >> m;
    int a[n]; for (auto &e : a) cin >> e;
    vector <pair <int, int>> v(n);
    for (int i = 0; i < n; i++) v[i] = make_pair(a[i], (i == p-1));
    int cnt = 0;
    while (m > 0) {
        int idx = 0, mn = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (v[i].first < mn) idx = i, mn = v[i].first;
            if (v[i].second) { mn = v[i].first, idx = i; break; }
        }
        if (v[idx].second) {
            if (m < mn) break;
            m -= mn;
            cnt++;
            pair <int, int> k = v[idx];
            v.erase(v.begin() + idx);
            v.emplace_back(k);
        } else {
            m -= mn;
            pair <int, int> k = v[idx];
            v.erase(v.begin() + idx);
            v.emplace_back(k);
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

