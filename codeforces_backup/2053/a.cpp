#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], ok = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int p = min(a[i], a[i+1]), q = max(a[i], a[i+1]);
        if (2*p > q) {ok = 1; break;}
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}