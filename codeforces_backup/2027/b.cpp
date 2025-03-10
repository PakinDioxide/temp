#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int mi = INT_MAX;
    for (int i = 0; i < n; i++) {
        int cnt = i;
        for (int j = i+1; j < n; j++) if (a[j] > a[i]) cnt++;
        mi = min(mi, cnt);
    }
    cout << mi << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}