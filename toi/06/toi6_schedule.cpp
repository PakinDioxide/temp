#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int ok[n+1], cnt = 0;
    vector <pair <int, int>> v;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        ok[i] = 0;
        v.emplace_back(l, i);
        v.emplace_back(r+1, -i);
    }
    sort(v.begin(), v.end());
    for (auto [x, k] : v) {
        if (k < 0) {
            k = -k;
            if (ok[k]) cnt--;
        } else if (cnt < m) cnt++, ok[k] = 1;
    }
    while (q--) {
        int k;
        cin >> k;
        cout << (ok[k] ? "Y " : "N ");
    }
}