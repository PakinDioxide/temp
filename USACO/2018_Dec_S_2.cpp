/*
    author  : PakinDioxide
    created : 21/03/2025 10:37
    task    : 2018_Dec_S_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n, idx = 0;
    cin >> n;
    tuple <ll, ll, ll> a[n];
    for (auto &[x, y, id] : a) cin >> x >> y, id = ++idx;
    priority_queue <tuple <ll, ll, ll>> q;
    sort(a, a+n);
    ll t = 0, mx = 0;
    idx = 0;
    while (!q.empty() || idx < n) {
        while ((idx < n && get<0>(a[idx]) <= t) || q.empty()) {
            auto [x, y, id] = a[idx];
            q.emplace(-id, x, y);
            idx++;
        }
        auto [iid, xx, yy] = q.top();
        // cout << xx << ' ' << yy << ' ' << t << '\n';
        q.pop();
        mx = max(mx, t - xx);
        t = max(t, xx) + yy;
    }
    cout << mx << '\n';
}