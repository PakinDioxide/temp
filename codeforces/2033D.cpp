#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    vector <pair <int, int>> v;
    v.emplace_back(0, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1], v.emplace_back(a[i], i);
    sort(v.begin(), v.end());  
    vector <pair <int, int>> k;
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i].first == v[i+1].first) k.emplace_back(v[i+1].second, v[i].second);
    }
    sort(k.begin(), k.end());
    if (k.size() == 0) {cout << 0 << '\n'; return;}
    // for (auto [x, y] : k) cout << x << ' ' << y << '\n';
    int cnt = 1, l = k[0].first;
    for (int i = 1; i < k.size(); i++) {
        if (k[i].second >= l) cnt++, l = k[i].first;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}