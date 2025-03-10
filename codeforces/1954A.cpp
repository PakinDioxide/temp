#include <bits/stdc++.h>

using namespace std;

int a[51], n, m, kk;

void solve() {
    cin >> n >> m >> kk;
    int k = 1, need = 0;
    for (int i = 1; i < n; i++) {
        a[i] = k%m;
        k++;
        if (a[i] != a[i-1]) need++;
        a[i] = a[i-1];
        if (need > kk) break;
    }
    if (need <= kk) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}