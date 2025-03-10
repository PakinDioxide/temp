#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n/2; i++) {
        if (a[i] == a[i-1]) swap(a[i], a[n-i-1]);
        else if (a[n-i-1] == a[n-i]) swap(a[i], a[n-i-1]);
    }
    int cnt = 0;
    for (int i = 0; i < n-1; i++) if (a[i] == a[i+1]) cnt++;
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}