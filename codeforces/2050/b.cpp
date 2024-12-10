#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], ok = 1, o = 0, e = 0, oo = 0, ee = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0) o+=a[i], oo++;
        else e += a[i], ee++;
    }
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    int sum = o+e;
    if (sum % n != 0 || o % oo != 0 || e % ee != 0) ok = 0;
    if (sum/n != o/oo || sum/n != e/ee || o/oo != e/ee) ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}