#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n], ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (i > 0) {
            if (b[i] < a[i-1]) ans += a[i-1] - b[i];
        }
    }
    cout << ans + a[n-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}