#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k, q;
    cin >> k >> q;
    int mi = INT_MAX;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        if (i == 0) mi = t-1;
    }
    while (q--) {
        int t;
        cin >> t;
        cout << min(t, mi) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}