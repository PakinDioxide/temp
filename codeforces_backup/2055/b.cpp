#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n], b[n], cnt = 0, mx = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i], cnt += (int) (a[i] < b[i]);
        if (a[i] < b[i]) mx = max(mx, b[i] - a[i]);
        else mn = min(mn, a[i] - b[i]);
    }
    if (cnt <= 1 && mx <= mn) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}