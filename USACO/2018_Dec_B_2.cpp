#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n;
    cin >> n;
    vector <pair <int, int>> v;
    for (int i = 0; i < n; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        v.emplace_back(s, b);
        v.emplace_back(t+1, -b);
    }
    sort(v.begin(), v.end());
    int mx = 0, cnt = 0;
    for (auto [idx, c] : v) cnt += c, mx = max(mx, cnt);
    cout << mx << '\n';
}