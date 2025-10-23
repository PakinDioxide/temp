#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    ll a[n], p[n], c = 0;
    priority_queue <pair <ll, ll>> q;
    for (auto &e : a) cin >> e;
    for (auto &e : p) cin >> e;
    for (int i = 0; i < n; i++) q.emplace(-p[i], a[i]);
    while (k > 0) {
        c += k;
        while (!q.empty() && q.top().second <= c) q.pop();
        if (q.empty()) { cout << "YES\n"; return; }
        k += q.top().first;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}